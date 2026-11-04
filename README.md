# Hi, I'm Saif 👋

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=26&pause=1000&color=2E9EF7&center=true&vCenter=true&width=800&lines=Building+AI+applications+with+Python+%26+LLMs;Agentic+workflows+%7C+LLM+APIs+%7C+Fine-tuning;Deep+Learning+on+SDSS+spectra" alt="Typing SVG" />
</div>

<p align="center">
  <a href="https://syedsaif101.github.io/portfolio/"><img src="https://img.shields.io/badge/Portfolio-000000?style=for-the-badge&logo=githubpages&logoColor=white" alt="Portfolio"/></a>
  <a href="https://www.linkedin.com/in/syed-saif-gillani-309078296/"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" alt="LinkedIn"/></a>
  <a href="mailto:saifgillani3@gmail.com"><img src="https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white" alt="Email"/></a>
</p>

Final-year **B.S. Space Science** student at the Institute of Space Technology, Islamabad. I build AI applications in Python: LLM-powered agents, API integrations, and ML pipelines that ship and run without babysitting.

- 🤖 **Now:** fine-tuning DistilGPT2 for next-word prediction, served through a FastAPI REST API
- 🔭 **Research:** deep-learning classification and redshift estimation of SDSS spectra (SARL–NCGSA, FYP)
- 🌱 **Learning next:** RAG with vector databases, tool calling, LangChain / LangGraph
- 🧑‍🤝‍🧑 **Leading:** the Google Quantum AI team at GDG on Campus IST

---

## 🛠️ Featured AI Work

### 🗞️ AI News-Posting Agent — *n8n · Gemini API · Telegram*
Scheduled agentic workflow for a client: pulls trending stories from **3 sources in parallel**, filters and normalises them with code nodes, then chains **two Gemini agents** (a classifier that picks relevant stories and a copywriter that rewrites them in brand voice) and posts to Telegram **every 12 hours** with no manual step.

```
Sources A/B/C ──► Filter + code ──► Merge ──► Gemini classifier ──► Gemini copywriter ──► Telegram (12h)
```

### ⌨️ Predictive Keyboard — *PyTorch · Hugging Face · FastAPI · Gradio* (in progress)
Context-aware next-word prediction. Fine-tunes **DistilGPT2** on MASSIVE en-US (+ OASST1, WikiText) through a config-driven pipeline and compares an **n-gram baseline vs pretrained vs fine-tuned** model. Served as a **REST/JSON API** with a Gradio demo; runs CPU-only. Tooling: pytest, Ruff, mypy, MLflow, Docker, GitHub Actions.

### 💬 Gemini API Chatbot — *Python · Gemini API*
Conversational chatbot built from scratch: each user message is sent with recent conversation context to the Gemini API and the reply is returned, a complete request/response loop over REST and JSON.

### 🔭 SDSS Spectra Pipeline for Deep Learning — *Python · NumPy · Astropy*
Downloaded and processed **15,955 FITS spectra** from SDSS DR18. Applied Savitzky–Golay smoothing, wavelength/redshift correction and power-law fitting to separate clean spectra from noisy ones before model training. [Report](https://syedsaif101.github.io/portfolio/Internship_SARL.pdf)

### ⚛️ Quantum Radar — IBM Quantum Hackathon — *Python · Qiskit*
Hybrid quantum-classical Battleship engine using the Quantum Zeno Effect. Raised interaction-free detection fidelity from **~25% to ~99.5%**, tested under ideal and noisy simulation. [Report](https://syedsaif101.github.io/portfolio/Hackathon_Report.pdf)

### ✉️ n8n Email Automation
Inbox trigger → sender/subject filter → templated reply → auto-send, removing a fully manual step.

---

## 🧰 Tech Stack

**Languages**
![Python](https://img.shields.io/badge/Python-3670A0?style=flat-square&logo=python&logoColor=ffdd54)
![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![SQL](https://img.shields.io/badge/SQL-07405e?style=flat-square&logo=mysql&logoColor=white)
![Bash](https://img.shields.io/badge/Bash-121011?style=flat-square&logo=gnubash&logoColor=white)
![R](https://img.shields.io/badge/R-276DC3?style=flat-square&logo=r&logoColor=white)

**AI / LLMs**
![Gemini](https://img.shields.io/badge/Gemini_API-8E75B2?style=flat-square&logo=googlegemini&logoColor=white)
![Hugging Face](https://img.shields.io/badge/Hugging_Face-FFD21E?style=flat-square&logo=huggingface&logoColor=black)
![PyTorch](https://img.shields.io/badge/PyTorch-EE4C2C?style=flat-square&logo=pytorch&logoColor=white)
![scikit-learn](https://img.shields.io/badge/scikit--learn-F7931E?style=flat-square&logo=scikitlearn&logoColor=white)
![n8n](https://img.shields.io/badge/n8n-EA4B71?style=flat-square&logo=n8n&logoColor=white)

**APIs & Backend**
![FastAPI](https://img.shields.io/badge/FastAPI-009688?style=flat-square&logo=fastapi&logoColor=white)
![Gradio](https://img.shields.io/badge/Gradio-F97316?style=flat-square&logo=gradio&logoColor=white)
![REST](https://img.shields.io/badge/REST_APIs-JSON-555?style=flat-square)

**Data**
![NumPy](https://img.shields.io/badge/NumPy-013243?style=flat-square&logo=numpy&logoColor=white)
![Pandas](https://img.shields.io/badge/Pandas-150458?style=flat-square&logo=pandas&logoColor=white)
![Matplotlib](https://img.shields.io/badge/Matplotlib-11557c?style=flat-square)
![Astropy](https://img.shields.io/badge/Astropy-D84315?style=flat-square)

**Tooling**
![Git](https://img.shields.io/badge/Git-F05033?style=flat-square&logo=git&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/GitHub_Actions-2088FF?style=flat-square&logo=githubactions&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=flat-square&logo=docker&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=flat-square&logo=linux&logoColor=black)
![Google Cloud](https://img.shields.io/badge/Google_Cloud-4285F4?style=flat-square&logo=googlecloud&logoColor=white)

---

## 📜 Selected Certifications

- **Google Prompting Essentials** — Google (Aug 2025)
- **AI For Everyone** — DeepLearning.AI (Mar 2025)
- **Python for Data Science, AI & Development** — IBM (Mar 2025)
- **Python Data Structures** — University of Michigan (Jun 2025)
- **Google Cybersecurity Professional Certificate** (Jul 2025) — [verify](https://www.coursera.org/account/accomplishments/professional-cert/OSZ9KNH8P43O)
- **Hands-on Quantum Error Correction** — Google Quantum AI (Jun 2025)

Full list (25+) on my [portfolio](https://syedsaif101.github.io/portfolio/#credentials).

---

## 🏆 Highlights

- **IAAC 2025 Qualification Round** — scored 24/25 (threshold 17), represented IST
- **GeoGenesis 2.0** GIS & RS workshop — climate data mapping with Python, GeoLLM (May 2025)

---

<p align="center">
  <img src="https://github-readme-stats.vercel.app/api?username=SyedSaif101&show_icons=true&hide_border=true&theme=tokyonight" height="150" alt="GitHub stats"/>
  <img src="https://github-readme-stats.vercel.app/api/top-langs/?username=SyedSaif101&layout=compact&hide_border=true&theme=tokyonight" height="150" alt="Top languages"/>
</p>
