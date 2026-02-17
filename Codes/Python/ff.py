from PIL import Image, ImageDraw, ImageFont
import textwrap

def create_resume_jpg():
    # 1. Setup blank white image (A4 ratio approx)
    width, height = 800, 1100
    background_color = (255, 255, 255)
    img = Image.new('RGB', (width, height), background_color)
    draw = ImageDraw.Draw(img)

    # 2. Define Content
    header = "SNEHALBEN DEVENDRABHAI MORI"
    contact = "Mobile: 9016700756  |  Email: morisnehal348@gmali.com"
    linkedin = "LinkedIn: linkedin.com/in/snehal-mori-26aa7a33b"
    
    sections = [
        ("PROFESSIONAL SUMMARY", "Motivated and compassionate BHMS student from Parul University with clinical internship experience at Jawaharlal Nehru Homoeopathic Medical College Hospital. Passionate about holistic, patient-centered care and looking to contribute to a reputed hospital or clinic as a junior doctor or medical officer."),
        ("WORK EXPERIENCE", "Medical Officer (IPD) - Ayushman Multi-speciality Hospital\n- Worked as a medical officer in IPD for 8 months."),
        ("EDUCATION", "Bachelor of Homeopathic Medicine and Surgery (BHMS)\nParul University, Jawaharlal Nehru Homoeopathic Medical College\n- Graduation: 2025"),
        ("INTERNSHIP EXPERIENCE", "Medical Intern - Jawaharlal Nehru Homoeopathic Medical College Hospital\n- Duration: 04/04/2024 to 03/04/2025\n- Assisted in patient diagnosis, treatment planning, and follow-up care\n- Conducted case taking, clinical assessments, and medical documentation"),
        ("SKILLS", "- Patient assessment and case taking\n- Emergency response (BLS, ACLS protocols)\n- Medical documentation and communication systems\n- Proficient in MS Office and basic EMR"),
        ("CERTIFICATIONS", "- Basic Life Support (BLS) - Pragya Lab\n- Advanced Cardiovascular Life Support (ACLS) - Pragya Lab\n- Comprehensive Emergency Training (CET) - Pragya Lab")
    ]

    # 3. Text Settings
    black = (0, 0, 0)
    blue = (0, 50, 150)
    try:
        # Try to use a standard font, fallback to default if missing
        font_header = ImageFont.truetype("arial.ttf", 24)
        font_sub = ImageFont.truetype("arial.ttf", 14)
        font_bold = ImageFont.truetype("arialbd.ttf", 14)
        font_text = ImageFont.truetype("arial.ttf", 12)
    except IOError:
        font_header = ImageFont.load_default()
        font_sub = ImageFont.load_default()
        font_bold = ImageFont.load_default()
        font_text = ImageFont.load_default()

    # 4. Drawing Logic
    y = 30
    # Header
    draw.text((width/2, y), header, fill=blue, font=font_header, anchor="ms")
    y += 30
    draw.text((width/2, y), contact, fill=black, font=font_sub, anchor="ms")
    y += 20
    draw.text((width/2, y), linkedin, fill=black, font=font_sub, anchor="ms")
    y += 40

    # Sections
    margin = 50
    content_width = width - (margin * 2)

    for title, body in sections:
        # Section Title
        draw.text((margin, y), title, fill=blue, font=font_bold)
        y += 20
        
        # Section Body
        lines = textwrap.wrap(body, width=95) # Approx char width for size 12 font
        for line in lines:
            draw.text((margin, y), line, fill=black, font=font_text)
            y += 18
        y += 15 # Space after section

    # 5. Save
    img.save("resume.jpg")
    print("Resume saved as resume.jpg")

if __name__ == "__main__":
    create_resume_jpg()