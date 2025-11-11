let editor = CodeMirror.fromTextArea(document.getElementById("codeEditor"), {
    mode: "text/x-c++src", 
    theme: "dracula",
    lineNumbers: true,
    autoCloseBrackets: true,
    matchBrackets: true
});


document.addEventListener("DOMContentLoaded", loadSnippets);

function saveSnippet(){
    let title = document.getElementById("snippetTitle").value.trim();
    if (!title) return alert("Please enter a title!");
    
    let snippets = getSnippets();
    snippets[title] = editor.getValue().trim();
    localStorage.setItem("snippets", JSON.stringify(snippets));

    loadSnippets();
    alert("Snippet saved!");
}

function loadSnippets(){
    let snippetList = document.getElementById("snippetList");
    snippetList.innerHTML = '';

    Object.keys(getSnippets()).forEach(title => {
        let li = document.createElement("li");
        li.textContent = title;
        li.onclick = () => loadSnippet(title);
        snippetList.appendChild(li);
    });
}

function loadSnippet(title){
    let snippets = getSnippets();
    document.getElementById("snippetTitle").value = title;
    editor.setValue(snippets[title]);
}

function clearCodes(){
    localStorage.removeItem("snippets");
    loadSnippets();
}

function runSnippet(){
    document.getElementById("output").textContent = "Code executed!";
}

function getSnippets(){
    return JSON.parse(localStorage.getItem("snippets")) || {};
}

function changeLanguage() {
    const selectedLang = document.getElementById("languageSelect").value;
    const mode = {
        clike: "text/x-c++src",
        javascript: "javascript",
        htmlmixed: "htmlmixed"
    };

    editor.setOption("mode", mode[selectedLang]);
}

function runSnippet() {
    const selectedLang = document.getElementById("languageSelect").value;
    const code = editor.getValue();
    const outputElement = document.getElementById("output"); // For JS & C++
    const outputFrame = document.getElementById("outputFrame"); // For HTML

    if (selectedLang === "javascript") {
        runJavaScript(code);
    } else if (selectedLang === "htmlmixed") {
        runHTMLSnippet(code);
    } else {
        outputElement.textContent = " Running C/C++ requires a backend compiler, which is not available here.";
    }
}

function runJavaScript(code) {
    const outputFrame = document.getElementById("outputFrame").contentWindow;
    const outputElement = document.getElementById("output");

    outputElement.textContent = "";
    outputFrame.document.open();
    outputFrame.document.write(`
        <script>
        try {
            const originalConsoleLog = console.log;
            let output = [];
            console.log = function(msg) {
                output.push(msg);
                originalConsoleLog.apply(console, arguments);
            };
            ${code}
            parent.document.getElementById('output').textContent = output.join('\\n') || ' Code executed successfully!';
        } catch (error) {
            parent.document.getElementById('output').textContent = " Error: " + error.message;
        }
        <\/script>
    `);
    outputFrame.document.close();
}


function runHTMLSnippet(code) {
    const outputFrame = document.getElementById("outputFrame").contentWindow.document;
    outputFrame.open(); 
    outputFrame.write(code); 
    outputFrame.close();
}



