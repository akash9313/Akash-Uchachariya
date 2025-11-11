let editor = CodeMirror.fromTextArea(document.getElementById("codeEditor"), {
    mode: "javascript",
    theme: "dracula",
    lineNumbers: true,
    autoCloseBrackets: true,
    matchBrackets: true
});
editor.setSize("100%", "400px");

document.addEventListener("DOMContentLoaded", loadSnippets);

function saveSnippet() {
    let title = document.getElementById("snippetTitle").value.trim();
    if (!title) return alert("Please enter a title!");

    let snippets = getSnippets();
    snippets[title] = editor.getValue().trim();
    localStorage.setItem("snippets", JSON.stringify(snippets));

    loadSnippets();
    alert("Snippet saved!");
}

function loadSnippets() {
    let snippetList = document.getElementById("snippetList");
    snippetList.innerHTML = '';

    Object.keys(getSnippets()).forEach(title => {
        let li = document.createElement("li");
        li.textContent = title;
        li.onclick = () => loadSnippet(title);
        snippetList.appendChild(li);
    });
}

function loadSnippet(title) {
    let snippets = getSnippets();
    document.getElementById("snippetTitle").value = title;
    editor.setValue(snippets[title]);
}

function clearCodes() {
    localStorage.removeItem("snippets");
    loadSnippets();
}

function getSnippets() {
    return JSON.parse(localStorage.getItem("snippets")) || {};
}

function changeLanguage() {
    const selectedLang = document.getElementById("languageSelect").value;
    const modeMap = {
        javascript: "javascript",
        htmlmixed: "htmlmixed"
    };
    editor.setOption("mode", modeMap[selectedLang]);
}

function runSnippet() {
    const selectedLang = document.getElementById("languageSelect").value;
    const code = editor.getValue();
    const output = document.getElementById("output");
    const frame = document.getElementById("outputFrame");

    if (selectedLang === "javascript") {
        frame.style.display = "none";
        output.style.display = "block";
        output.textContent = "";

        try {
            let consoleOutput = [];
            const originalLog = console.log;
            console.log = (...args) => consoleOutput.push(args.join(" "));
            eval(code);
            console.log = originalLog;

            output.textContent = consoleOutput.join("\n") || "Code executed successfully!";
        } catch (err) {
            output.textContent = "Error: " + err.message;
        }

    } else if (selectedLang === "htmlmixed") {
        frame.style.display = "block";
        output.style.display = "block";
        frame.srcdoc = code;
        output.textContent = "HTML output shown above.";
    }
}
