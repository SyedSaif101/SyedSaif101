<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Syed Saif Gillani — AI, ML & Space Science</title>
<meta name="description" content="Portfolio of Syed Saif Gillani — computational astrophysics, machine learning, cybersecurity, and automation.">
<link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Fraunces:opsz,wght@9..144,300;9..144,500;9..144,600;9..144,700&family=Inter:wght@400;500;600&family=JetBrains+Mono:wght@400;500&display=swap" rel="stylesheet">
<style>
  :root{
    --bg: #0A0E14;
    --surface: #10151F;
    --surface-2: #161C29;
    --line: #232B3B;
    --text: #E8E6DF;
    --text-muted: #8B93A3;
    --violet: #9C8FF0;
    --teal: #4FD1C5;
    --amber: #E8A855;
  }
  *{margin:0;padding:0;box-sizing:border-box;}
  html{scroll-behavior:smooth;}
  @media (prefers-reduced-motion: reduce){
    html{scroll-behavior:auto;}
    *{animation-duration:0.01ms !important; animation-iteration-count:1 !important; transition-duration:0.01ms !important;}
  }
  body{
    background:var(--bg);
    color:var(--text);
    font-family:'Inter', sans-serif;
    line-height:1.6;
    overflow-x:hidden;
  }
  a{color:inherit;text-decoration:none;}
  .mono{font-family:'JetBrains Mono', monospace;}
  ::selection{background:var(--violet); color:var(--bg);}

  /* ---------- Layout helpers ---------- */
  .wrap{max-width:1080px;margin:0 auto;padding:0 32px;}
  section{position:relative;}
  .eyebrow{
    font-family:'JetBrains Mono', monospace;
    font-size:12px;
    letter-spacing:0.12em;
    text-transform:uppercase;
    color:var(--teal);
    display:flex;
    align-items:center;
    gap:10px;
    margin-bottom:18px;
  }
  .eyebrow::before{
    content:'';
    width:22px;height:1px;
    background:var(--teal);
    display:inline-block;
  }
  h1,h2,h3{font-family:'Fraunces', serif; font-weight:600; letter-spacing:-0.01em;}

  /* ---------- Nav ---------- */
  nav{
    position:fixed; top:0; left:0; right:0; z-index:100;
    backdrop-filter:blur(10px);
    background:rgba(10,14,20,0.72);
    border-bottom:1px solid var(--line);
  }
  .nav-inner{
    max-width:1080px;margin:0 auto;padding:18px 32px;
    display:flex;align-items:center;justify-content:space-between;
  }
  .nav-logo{font-family:'JetBrains Mono'; font-size:14px; letter-spacing:0.05em; color:var(--text);}
  .nav-logo span{color:var(--violet);}
  .nav-links{display:flex; gap:28px; font-size:13px; font-family:'JetBrains Mono';}
  .nav-links a{color:var(--text-muted); transition:color .2s;}
  .nav-links a:hover{color:var(--text);}
  .nav-links a:focus-visible, a:focus-visible, button:focus-visible{outline:2px solid var(--teal); outline-offset:3px;}
  @media(max-width:640px){ .nav-links{display:none;} }

  /* ---------- Hero ---------- */
  .hero{
    min-height:100svh;
    display:flex; flex-direction:column; justify-content:center;
    padding-top:90px; padding-bottom:60px;
    position:relative;
  }
  .hero .wrap{position:relative; z-index:2;}
  .hero-kicker{
    font-family:'JetBrains Mono'; font-size:13px; color:var(--text-muted);
    letter-spacing:0.08em; margin-bottom:22px; text-transform:uppercase;
  }
  .hero h1{
    font-size:clamp(2.4rem, 6vw, 4.6rem);
    line-height:1.04;
    max-width:14ch;
    color:var(--text);
  }
  .hero h1 em{
    font-style:italic; font-weight:500; color:var(--violet);
  }
  .hero p{
    margin-top:26px;
    max-width:52ch;
    color:var(--text-muted);
    font-size:1.05rem;
  }
  .hero-cta{display:flex; gap:16px; margin-top:38px; flex-wrap:wrap;}
  .btn{
    font-family:'JetBrains Mono'; font-size:13px;
    padding:13px 22px; border-radius:2px;
    border:1px solid var(--line);
    transition:all .2s ease;
    display:inline-flex; align-items:center; gap:8px;
  }
  .btn-primary{background:var(--text); color:var(--bg); border-color:var(--text);}
  .btn-primary:hover{background:var(--violet); border-color:var(--violet);}
  .btn-ghost:hover{border-color:var(--text-muted); color:var(--text);}

  /* Spectral signature graphic */
  .spectrum-wrap{
    position:absolute; inset:0; z-index:1;
    display:flex; align-items:flex-end; justify-content:center;
    opacity:0.9;
    pointer-events:none;
  }
  svg.hero-spectrum{width:100%; max-width:1080px; height:38svh;}
  .spectral-line{
    fill:none; stroke-width:1.6;
    stroke-dasharray:2200;
    stroke-dashoffset:2200;
    animation:draw 2.6s cubic-bezier(.16,.8,.3,1) forwards;
  }
  @keyframes draw{ to{stroke-dashoffset:0;} }
  .peak-label{ font-family:'JetBrains Mono'; font-size:9px; fill:var(--text-muted); opacity:0; animation:fadein 1s ease forwards; animation-delay:2.2s;}
  @keyframes fadein{ to{opacity:0.8;} }

  /* Divider strip used between sections — encodes a spectrum readout */
  .divider{
    height:64px; border-top:1px solid var(--line); border-bottom:1px solid var(--line);
    display:flex; align-items:center; overflow:hidden;
    background:var(--surface);
  }
  .divider-track{ display:flex; gap:3px; padding:0 32px; width:100%; }
  .divider-bar{ width:3px; background:var(--line); flex-shrink:0; }

  /* ---------- Section generic ---------- */
  .section{padding:110px 0;}
  .section-head{ max-width:640px; margin-bottom:56px; }
  .section-head h2{ font-size:clamp(1.8rem,3.4vw,2.6rem); }
  .section-head p{ color:var(--text-muted); margin-top:14px; font-size:1rem; }

  /* ---------- About ---------- */
  .about-grid{
    display:grid; grid-template-columns: 1fr 1.3fr; gap:64px;
  }
  @media(max-width:820px){ .about-grid{grid-template-columns:1fr;} }
  .about-stats{ display:flex; flex-direction:column; gap:26px; }
  .stat{ border-left:2px solid var(--violet); padding-left:18px; }
  .stat .num{ font-family:'Fraunces'; font-size:2rem; color:var(--text); display:block; }
  .stat .label{ font-family:'JetBrains Mono'; font-size:12px; color:var(--text-muted); text-transform:uppercase; letter-spacing:.05em;}
  .about-body p{ margin-bottom:18px; color:var(--text-muted); }
  .about-body strong{ color:var(--text); font-weight:600; }

  /* ---------- Work / research cards ---------- */
  .track-tabs{
    display:flex; gap:8px; margin-bottom:44px; flex-wrap:wrap;
  }
  .tab{
    font-family:'JetBrains Mono'; font-size:12.5px;
    padding:9px 16px; border:1px solid var(--line); border-radius:20px;
    color:var(--text-muted); cursor:pointer; transition:all .2s; background:transparent;
  }
  .tab.active{ color:var(--bg); background:var(--teal); border-color:var(--teal); }
  .tab:hover:not(.active){ border-color:var(--text-muted); color:var(--text); }

  .card-grid{ display:grid; grid-template-columns:repeat(2,1fr); gap:22px; }
  @media(max-width:760px){ .card-grid{grid-template-columns:1fr;} }
  .card{
    background:var(--surface); border:1px solid var(--line);
    padding:28px; border-radius:4px;
    transition:border-color .25s, transform .25s;
  }
  .card:hover{ border-color:var(--violet); transform:translateY(-3px); }
  .card-tag{
    font-family:'JetBrains Mono'; font-size:10.5px; color:var(--amber);
    text-transform:uppercase; letter-spacing:.08em; margin-bottom:12px; display:block;
  }
  .card h3{ font-size:1.15rem; font-weight:600; margin-bottom:10px; color:var(--text); font-family:'Inter'; }
  .card p{ color:var(--text-muted); font-size:.92rem; margin-bottom:14px; }
  .card ul{ list-style:none; display:flex; flex-wrap:wrap; gap:8px; }
  .card ul li{
    font-family:'JetBrains Mono'; font-size:10.5px; color:var(--text-muted);
    border:1px solid var(--line); padding:4px 9px; border-radius:20px;
  }
  .track-panel{ display:none; }
  .track-panel.active{ display:block; animation:fadeup .4s ease; }
  @keyframes fadeup{ from{opacity:0; transform:translateY(8px);} to{opacity:1; transform:translateY(0);} }

  /* ---------- Certifications ---------- */
  .cert-table{ width:100%; border-collapse:collapse; font-family:'JetBrains Mono'; font-size:12.5px; }
  .cert-table tr{ border-bottom:1px solid var(--line); }
  .cert-table td{ padding:13px 10px; color:var(--text-muted); vertical-align:top; }
  .cert-table td.cname{ color:var(--text); font-family:'Inter'; font-size:13.5px; font-weight:500; }
  .cert-table td.cdate{ white-space:nowrap; color:var(--teal); text-align:right; }
  .cert-table tr:hover td{ color:var(--text); }
  .cert-more{ margin-top:22px; color:var(--text-muted); font-size:13px; }

  /* ---------- Contact ---------- */
  .contact-inner{
    display:flex; flex-direction:column; align-items:flex-start; gap:28px;
  }
  .contact-links{ display:flex; gap:16px; flex-wrap:wrap; margin-top:10px; }

  footer{
    border-top:1px solid var(--line);
    padding:32px;
    text-align:center;
    font-family:'JetBrains Mono'; font-size:11.5px; color:var(--text-muted);
  }
</style>
</head>
<body>

<nav>
  <div class="nav-inner">
    <div class="nav-logo">SSG<span>.</span></div>
    <div class="nav-links">
      <a href="#about">About</a>
      <a href="#work">Work</a>
      <a href="#credentials">Credentials</a>
      <a href="#contact">Contact</a>
    </div>
  </div>
</nav>

<header class="hero">
  <div class="spectrum-wrap">
    <svg class="hero-spectrum" viewBox="0 0 1080 340" preserveAspectRatio="xMidYMax meet" aria-hidden="true">
      <path class="spectral-line" stroke="#232B3B" d="M0,300 L1080,300"/>
      <path class="spectral-line" stroke="#9C8FF0" style="animation-delay:.1s"
        d="M0,300 L120,298 L200,296 L260,180 L280,60 L300,180 L340,296 L460,294 L520,296 L560,150 L580,40 L600,150 L640,296 L760,292 L820,290 L850,200 L870,90 L890,200 L920,290 L1080,286"/>
      <text class="peak-label" x="270" y="52" text-anchor="middle">Hα</text>
      <text class="peak-label" x="570" y="32" text-anchor="middle" style="animation-delay:2.35s">[OIII]</text>
      <text class="peak-label" x="860" y="82" text-anchor="middle" style="animation-delay:2.45s">Hβ</text>
    </svg>
  </div>
  <div class="wrap">
    <div class="hero-kicker">Syed Saif Gillani — Islamabad, Pakistan</div>
    <h1>Reading signal<br>out of <em>noise.</em></h1>
    <p>Space science undergraduate building AI applications in Python — LLM-powered agents, fine-tuned transformers, and deep-learning pipelines that classify galaxies from their spectra — with a security mindset and an eye for automating the boring parts.</p>
    <div class="hero-cta">
      <a href="#work" class="btn btn-primary">See the work →</a>
      <a href="mailto:saifgillani3@gmail.com" class="btn btn-ghost">Get in touch</a>
    </div>
  </div>
</header>

<div class="divider" aria-hidden="true">
  <div class="divider-track" id="divider1"></div>
</div>

<section class="section" id="about">
  <div class="wrap about-grid">
    <div class="about-stats">
      <div class="stat"><span class="num">3.30</span><span class="label">CGPA · B.S. Space Science</span></div>
      <div class="stat"><span class="num">25+</span><span class="label">Certifications completed</span></div>
      <div class="stat"><span class="num">1 yr+</span><span class="label">AGN research at SARL–NCGSA</span></div>
    </div>
    <div class="about-body">
      <div class="eyebrow">About</div>
      <p>I'm a final-year <strong>Space Science</strong> student at the Institute of Space Technology, Islamabad, working as a <strong>Research Intern</strong> at the Space and Astrophysics Research Lab, where I study SDSS spectral data to classify AGN and other celestial objects using deep learning.</p>
      <p>In parallel, I lead the <strong>Quantum AI team</strong> at Google Developer Group on Campus, hold Google's Cybersecurity Professional Certificate, and build AI tooling — from Gemini-powered agent workflows to fine-tuned language models served over REST APIs — that removes repetitive work from research and everyday tasks.</p>
      <p>I'm also building a freelance track to work with international clients, and tutor mathematics and physics on the side.</p>
    </div>
  </div>
</section>

<div class="divider" aria-hidden="true">
  <div class="divider-track" id="divider2"></div>
</div>

<section class="section" id="work">
  <div class="wrap">
    <div class="section-head">
      <div class="eyebrow">Selected work</div>
      <h2>Four tracks, one method</h2>
      <p>Filter by domain — each project follows the same approach: understand the system, build the pipeline, ship something that works.</p>
    </div>

    <div class="track-tabs" role="tablist">
      <button class="tab active" data-track="ai" role="tab" aria-selected="true">AI & LLM Apps</button>
      <button class="tab" data-track="astro" role="tab" aria-selected="false">Astrophysics & ML</button>
      <button class="tab" data-track="security" role="tab" aria-selected="false">Cybersecurity</button>
      <button class="tab" data-track="automation" role="tab" aria-selected="false">Automation & Systems</button>
    </div>

    <div class="track-panel active" data-panel="ai">
      <div class="card-grid">
        <div class="card" style="grid-column: 1 / -1;">
          <span class="card-tag">In progress · Transformer fine-tuning</span>
          <h3>Predictive Keyboard — Context-Aware Next-Word Prediction</h3>
          <p>Fine-tunes DistilGPT2 on MASSIVE en-US (plus OASST1 and WikiText) through a config-driven pipeline, and benchmarks an n-gram baseline against the pretrained and fine-tuned models. Predictions are served through a FastAPI REST endpoint returning JSON, with a Gradio demo, and run CPU-only on a laptop.</p>
          <ul><li>PyTorch</li><li>Hugging Face</li><li>FastAPI</li><li>Gradio</li><li>MLflow</li><li>GitHub Actions</li></ul>
          <a href="https://github.com/SyedSaif101" target="_blank" rel="noopener" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View on GitHub ↗</a>
        </div>
        <div class="card" style="grid-column: 1 / -1;">
  <span class="card-tag">n8n · AI Newsposting</span>
  <h3>Trending news → brand voice → Telegram, every 12 hours</h3>
  <p>Scheduled trigger pulls trending stories from multiple sources in parallel, filters and codes each branch, merges and aggregates them, then runs the result through a Gemini-based classifier and copywriter agent before posting to the client's Telegram channel.</p>
  <svg viewBox="0 0 900 200" style="width:100%; height:auto; margin:18px 0 10px;" role="img" aria-label="n8n workflow diagram: three parallel news sources merge, get classified and rewritten by AI agents, then post to Telegram">
    <defs>
      <marker id="wf-arrow-1" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
        <path d="M2 1L8 5L2 9" fill="none" stroke="#8B93A3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
      </marker>
    </defs>
    <line x1="30" y1="40" x2="130" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4"/>
    <line x1="30" y1="100" x2="130" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4"/>
    <line x1="30" y1="160" x2="130" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4"/>
    <line x1="170" y1="100" x2="290" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-1)"/>
    <line x1="330" y1="100" x2="450" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-1)"/>
    <line x1="490" y1="100" x2="610" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-1)"/>
    <line x1="650" y1="100" x2="800" y2="100" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-1)"/>

    <text x="30" y="34" text-anchor="middle" fill="#8B93A3" font-family="JetBrains Mono" font-size="9">SOURCE A</text>
    <circle cx="30" cy="40" r="5" fill="#4FD1C5"/>
    <text x="30" y="94" text-anchor="middle" fill="#8B93A3" font-family="JetBrains Mono" font-size="9">SOURCE B</text>
    <circle cx="30" cy="100" r="5" fill="#4FD1C5"/>
    <text x="30" y="154" text-anchor="middle" fill="#8B93A3" font-family="JetBrains Mono" font-size="9">SOURCE C</text>
    <circle cx="30" cy="160" r="5" fill="#4FD1C5"/>

    <circle cx="150" cy="100" r="38" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5"/>
    <text x="150" y="97" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="9">FILTER</text>
    <text x="150" y="110" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">+ code</text>

    <circle cx="310" cy="100" r="38" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="310" y="97" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">MERGE</text>
    <text x="310" y="110" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">append</text>

    <circle cx="470" cy="100" r="38" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="470" y="97" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">CLASSIFY</text>
    <text x="470" y="110" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Gemini agent</text>

    <circle cx="630" cy="100" r="38" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="630" y="97" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">REWRITE</text>
    <text x="630" y="110" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">brand voice</text>

    <circle cx="800" cy="100" r="38" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="800" y="97" text-anchor="middle" fill="#E8A855" font-family="JetBrains Mono" font-size="9">TELEGRAM</text>
    <text x="800" y="110" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">every 12h</text>
  </svg>
</div>
        <div class="card" style="grid-column: 1 / -1;">
  <span class="card-tag">Applied AI · Gemini Chatbot</span>
  <h3>Message in → Gemini reasoning → reply out</h3>
  <p>User message is captured, sent to the Gemini API along with recent conversation context, and the generated response is returned to the user — a minimal but complete conversational loop built from scratch.</p>
  <svg viewBox="0 0 900 180" style="width:100%; height:auto; margin:18px 0 10px;" role="img" aria-label="Gemini chatbot diagram: user input, Gemini API processing with context, response generation, and reply delivery">
    <defs>
      <marker id="wf-arrow-5" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
        <path d="M2 1L8 5L2 9" fill="none" stroke="#8B93A3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
      </marker>
    </defs>
    <line x1="90" y1="90" x2="210" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-5)"/>
    <line x1="250" y1="90" x2="370" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-5)"/>
    <line x1="410" y1="90" x2="530" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-5)"/>
    <line x1="290" y1="60" x2="290" y2="30" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="3 3"/>
    <line x1="290" y1="30" x2="290" y2="30" stroke="#232B3B" stroke-width="1.5"/>

    <circle cx="50" cy="90" r="40" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5"/>
    <text x="50" y="87" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="9">INPUT</text>
    <text x="50" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">User message</text>

    <circle cx="230" cy="90" r="40" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="230" y="87" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">GEMINI API</text>
    <text x="230" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Process intent</text>

    <rect x="255" y="10" width="70" height="24" rx="12" fill="#161C29" stroke="#232B3B"/>
    <text x="290" y="26" text-anchor="middle" fill="#8B93A3" font-family="JetBrains Mono" font-size="8">context</text>

    <circle cx="390" cy="90" r="40" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="390" y="87" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">GENERATE</text>
    <text x="390" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Compose reply</text>

    <circle cx="550" cy="90" r="40" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="550" y="87" text-anchor="middle" fill="#E8A855" font-family="JetBrains Mono" font-size="9">DELIVER</text>
    <text x="550" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Reply shown</text>
  </svg>
</div>
      </div>
    </div>

    <div class="track-panel" data-panel="astro">
      <div class="card-grid">
       <div class="card">
  <span class="card-tag">Research · SARL–NCGSA</span>
  <h3>SDSS Quasar Spectra — Deep Learning Classification</h3>
  <p>Built a pipeline to explore and prepare SDSS quasar spectra for deep learning: downloaded 15,955 FITS files from DR18, applied Savitzky–Golay smoothing, wavelength/redshift correction, and power-law fitting to separate clean spectra from noisy ones ahead of model training.</p>
  <ul><li>Python</li><li>Astropy</li><li>NumPy</li><li>SDSS DR18</li></ul>
  <a href="Internship_SARL.pdf" target="_blank" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View report PDF ↗</a>
</div>
        <div class="card">
  <span class="card-tag">IBM Quantum Hackathon</span>
  <h3>Quantum Radar — Interaction-Free Ship Detection</h3>
  <p>Built a hybrid quantum-classical Battleship engine that finds ships without "hitting" them, using the Quantum Zeno Effect to push interaction-free detection fidelity from ~25% (basic Elitzur–Vaidman) to ~99.5%. Classical game logic in Python, detection oracle in Qiskit, tested under both ideal and noisy simulation.</p>
  <ul><li>Qiskit</li><li>Python</li><li>Quantum Zeno Effect</li></ul>
  <a href="Hackathon_Report.pdf" target="_blank" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View report PDF ↗</a>
</div>
        
        <div class="card">
          <span class="card-tag">Report</span>
          <h3>Dark Matter & Dark Energy</h3>
          <p>A research report reviewing current theory and observational evidence on dark matter and dark energy, and their role in cosmic structure and expansion.</p>
          <ul><li>Cosmology</li><li>Literature Review</li></ul>
        </div>
      </div>
    </div>

    <div class="track-panel" data-panel="security">
      <div class="card-grid">
        <div class="card">
          <span class="card-tag">Google Cloud KMS</span>
          <h3>Asymmetric Encryption — Sign & Verify</h3>
          <p>Generated an RSA key pair in Google Cloud KMS to digitally sign files, then verified signatures with the public key to demonstrate tamper detection and data integrity.</p>
          <ul><li>OpenSSL</li><li>Google Cloud KMS</li><li>RSA</li></ul>
          <a href="Asymmetric_Encryption_to_Sign_and_Verify_Data.pdf" target="_blank" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View report PDF ↗</a>
        </div>
        <div class="card">
          <span class="card-tag">Design exercise</span>
          <h3>Security Infrastructure for an E-Commerce Company</h3>
          <p>Designed a full security plan covering MFA, RBAC, VPN remote access, firewall rules, VLAN segmentation, endpoint protection, and IDS — aligned with PCI DSS and GDPR.</p>
          <ul><li>Network Security</li><li>PCI DSS</li><li>GDPR</li></ul>
          <a href="Security_Infrastructure_Design.pdf" target="_blank" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View report PDF ↗</a>
        </div>
        <div class="card">
          <span class="card-tag">Pentest</span>
          <h3>OWASP Juice Shop Penetration Test</h3>
          <p>Hands-on penetration test against the intentionally vulnerable OWASP Juice Shop application, practicing common web exploitation techniques.</p>
          <ul><li>Web AppSec</li><li>OWASP</li></ul>
        </div>
        <div class="card">
          <span class="card-tag">Coursework</span>
          <h3>Linux Shell Scripting & Filesystem Administration</h3>
          <p>Wrote and debugged Bash scripts for system administration workflows, and worked hands-on with Linux file permissions, directory structures, and symbolic/hard links.</p>
          <ul><li>Bash</li><li>Linux</li></ul>
          <a href="Linux_Shell_Scripting.pdf" target="_blank" class="btn btn-ghost" style="margin-top:14px; font-size:11px; padding:8px 14px;">View report PDF ↗</a>
        </div>
      </div>
    </div>

    <div class="track-panel" data-panel="automation">
      <div class="card-grid">
<div class="card" style="grid-column: 1 / -1;">
  <span class="card-tag">n8n · Email Automation</span>
  <h3>Inbox trigger → smart reply → auto-send</h3>
  <p>Watches an inbox for new messages, filters by sender and subject criteria, generates a templated response based on the message content, and sends the reply automatically — removing a fully manual, repetitive step from the workflow.</p>
  <svg viewBox="0 0 900 180" style="width:100%; height:auto; margin:18px 0 10px;" role="img" aria-label="n8n email automation diagram: inbox trigger, filter, template generation, and auto-send in sequence">
    <defs>
      <marker id="wf-arrow-4" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
        <path d="M2 1L8 5L2 9" fill="none" stroke="#8B93A3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
      </marker>
    </defs>
    <line x1="90" y1="90" x2="210" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-4)"/>
    <line x1="250" y1="90" x2="370" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-4)"/>
    <line x1="410" y1="90" x2="530" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-4)"/>
    <line x1="570" y1="90" x2="690" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-4)"/>

    <circle cx="50" cy="90" r="40" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5"/>
    <text x="50" y="87" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="9">TRIGGER</text>
    <text x="50" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">New email</text>

    <circle cx="230" cy="90" r="40" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="230" y="87" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">FILTER</text>
    <text x="230" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Sender / subject</text>

    <circle cx="390" cy="90" r="40" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="390" y="87" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="9">GENERATE</text>
    <text x="390" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Templated reply</text>

    <circle cx="550" cy="90" r="40" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="550" y="87" text-anchor="middle" fill="#E8A855" font-family="JetBrains Mono" font-size="9">SEND</text>
    <text x="550" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Auto-reply</text>

    <circle cx="750" cy="90" r="34" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5" stroke-dasharray="3 3"/>
    <text x="750" y="87" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="8">DONE</text>
    <text x="750" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">Logged</text>
  </svg>
</div>
<div class="card" style="grid-column: 1 / -1;">
  <span class="card-tag">Make · Template study</span>
  <h3>One approved asset → multi-platform social post</h3>
  <p>Sheet-driven trigger pulls approved content, fetches the asset from storage, notifies the team, updates status, then routes the same post to Instagram and Facebook in parallel.</p>
  <svg viewBox="0 0 980 180" style="width:100%; height:auto; margin:18px 0 10px;" role="img" aria-label="Make.com workflow diagram: sheet trigger through file handling and notification to a router splitting into Instagram and Facebook posting">
    <defs>
      <marker id="wf-arrow-2" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
        <path d="M2 1L8 5L2 9" fill="none" stroke="#8B93A3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
      </marker>
    </defs>
    <line x1="86" y1="90" x2="156" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="196" y1="90" x2="266" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="306" y1="90" x2="376" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="416" y1="90" x2="486" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="526" y1="90" x2="596" y2="90" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="636" y1="90" x2="750" y2="45" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>
    <line x1="636" y1="90" x2="750" y2="135" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-2)"/>

    <circle cx="46" cy="90" r="38" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5"/>
    <text x="46" y="87" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="8.5">TRIGGER</text>
    <text x="46" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Sheet update</text>

    <circle cx="176" cy="90" r="32" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="176" y="93" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Repeater</text>

    <circle cx="286" cy="90" r="32" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="286" y="93" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Fetch file</text>

    <circle cx="396" cy="90" r="32" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="396" y="93" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Notify team</text>

    <circle cx="506" cy="90" r="32" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="506" y="93" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Update row</text>

    <circle cx="616" cy="90" r="32" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="616" y="87" text-anchor="middle" fill="#E8A855" font-family="JetBrains Mono" font-size="8.5">ROUTER</text>
    <text x="616" y="100" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Split</text>

    <circle cx="800" cy="45" r="36" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="800" y="48" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Instagram</text>

    <circle cx="800" cy="135" r="36" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="800" y="138" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Facebook</text>
  </svg>
</div>

<div class="card" style="grid-column: 1 / -1;">
  <span class="card-tag">Zapier · Template study</span>
  <h3>Webhook → enrichment → AI-driven branching</h3>
  <p>Inbound webhook enriches the lead via Clearbit, then splits into three intelligent paths — nurture sequence, high-priority AI response, or an auto-created support ticket — based on the lead's profile and intent.</p>
  <svg viewBox="0 0 900 280" style="width:100%; height:auto; margin:18px 0 10px;" role="img" aria-label="Zapier workflow diagram: webhook and enrichment feeding a path split into three branches for lead nurture, priority response, and support ticketing">
    <defs>
      <marker id="wf-arrow-3" viewBox="0 0 10 10" refX="8" refY="5" markerWidth="6" markerHeight="6" orient="auto-start-reverse">
        <path d="M2 1L8 5L2 9" fill="none" stroke="#8B93A3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"/>
      </marker>
    </defs>
    <line x1="80" y1="45" x2="200" y2="45" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>
    <line x1="270" y1="45" x2="390" y2="45" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>

    <line x1="410" y1="60" x2="150" y2="125" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>
    <line x1="420" y1="65" x2="450" y2="125" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>
    <line x1="430" y1="60" x2="750" y2="125" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>

    <line x1="150" y1="155" x2="150" y2="195" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>
    <line x1="450" y1="155" x2="450" y2="195" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>
    <line x1="750" y1="155" x2="750" y2="195" stroke="#232B3B" stroke-width="1.5" stroke-dasharray="4 4" marker-end="url(#wf-arrow-3)"/>

    <circle cx="40" cy="45" r="36" fill="#161C29" stroke="#4FD1C5" stroke-width="1.5"/>
    <text x="40" y="42" text-anchor="middle" fill="#4FD1C5" font-family="JetBrains Mono" font-size="8.5">WEBHOOK</text>
    <text x="40" y="55" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Catch hook</text>

    <circle cx="235" cy="45" r="36" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="235" y="42" text-anchor="middle" fill="#9C8FF0" font-family="JetBrains Mono" font-size="8.5">ENRICH</text>
    <text x="235" y="55" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Find person</text>

    <circle cx="420" cy="45" r="30" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="420" y="42" text-anchor="middle" fill="#E8A855" font-family="JetBrains Mono" font-size="8.5">PATHS</text>
    <text x="420" y="55" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8.5">Split</text>

    <rect x="90" y="125" width="120" height="30" rx="15" fill="#161C29" stroke="#232B3B"/>
    <text x="150" y="144" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Lead nurture</text>
    <circle cx="150" cy="232" r="36" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="150" y="230" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">ChatGPT</text>
    <text x="150" y="241" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">prompt</text>

    <rect x="390" y="125" width="120" height="30" rx="15" fill="#161C29" stroke="#232B3B"/>
    <text x="450" y="144" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">High priority</text>
    <circle cx="450" cy="232" r="36" fill="#161C29" stroke="#9C8FF0" stroke-width="1.5"/>
    <text x="450" y="230" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">AI</text>
    <text x="450" y="241" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">response</text>

    <rect x="690" y="125" width="120" height="30" rx="15" fill="#161C29" stroke="#232B3B"/>
    <text x="750" y="144" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="9">Support intent</text>
    <circle cx="750" cy="232" r="36" fill="#161C29" stroke="#E8A855" stroke-width="1.5"/>
    <text x="750" y="230" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">Zendesk</text>
    <text x="750" y="241" text-anchor="middle" fill="#E8E6DF" font-family="Inter" font-size="8">ticket</text>
  </svg>
</div>
        <div class="card">
          <span class="card-tag">Leadership</span>
          <h3>Team Lead, Google Quantum AI — GDG IST</h3>
          <p>Lead and coordinate the Quantum AI team: defining project milestones, mentoring members through quantum computing and AI fundamentals, and running candidate interviews.</p>
          <ul><li>Quantum Computing</li><li>Mentorship</li></ul>
        </div>
        <div class="card">
          <span class="card-tag">Hardware</span>
          <h3>Bluetooth-Controlled RC Car</h3>
          <p>Built an Arduino RC car using an L298N motor driver and HC-05 Bluetooth module, tracing and resolving TXD/RXD wiring faults along the way.</p>
          <ul><li>Arduino</li><li>Embedded</li></ul>
        </div>
        <div class="card">
          <span class="card-tag">Database</span>
          <h3>Census Management System</h3>
          <p>Designed a full MySQL database for a census system — schema, 90+ seed records, 20 queries — with accompanying documentation and report.</p>
          <ul><li>MySQL</li><li>Database Design</li></ul>
        </div>
      </div>
    </div>
  </div>
</section>

<div class="divider" aria-hidden="true">
  <div class="divider-track" id="divider3"></div>
</div>

<section class="section" id="credentials">
  <div class="wrap">
    <div class="section-head">
      <div class="eyebrow">Credentials</div>
      <h2>25+ certifications, one throughline</h2>
      <p>Cybersecurity, Python, and quantum/AI fundamentals — mostly Google, Coursera, and university-issued, completed through 2025.</p>
    </div>
    <table class="cert-table">
      <tr><td class="cname">Google Cybersecurity Professional Certificate</td><td>Linux, SIEM, SQL, Python, Incident Response</td><td class="cdate">Jul 2025</td></tr>
      <tr><td class="cname">EC-Council Ethical Hacking Essentials (EHE)</td><td>Threat Detection</td><td class="cdate">Jun 2025</td></tr>
      <tr><td class="cname">IT Security: Defense Against the Digital Dark Arts</td><td>Malware Detection, SIEM</td><td class="cdate">Sep 2025</td></tr>
      <tr><td class="cname">Office of the CISO Institute: Cybersecurity Essentials</td><td>Cloud Security, Authentication</td><td class="cdate">Sep 2025</td></tr>
      <tr><td class="cname">Automate Cybersecurity Tasks with Python</td><td>Python, Algorithms</td><td class="cdate">Jul 2025</td></tr>
      <tr><td class="cname">Sound the Alarm: Detection and Response</td><td>SIEM</td><td class="cdate">Jul 2025</td></tr>
      <tr><td class="cname">Assets, Threats, and Vulnerabilities</td><td>NIST 800-53, Cryptography</td><td class="cdate">Jul 2025</td></tr>
      <tr><td class="cname">Connect and Protect: Networks and Network Security</td><td>Network Architecture</td><td class="cdate">May 2025</td></tr>
      <tr><td class="cname">Play It Safe: Manage Security Risks</td><td>Security Audits</td><td class="cdate">Apr 2025</td></tr>
      <tr><td class="cname">Foundations of Cybersecurity</td><td>Cybersecurity Fundamentals</td><td class="cdate">Mar 2025</td></tr>
      <tr><td class="cname">Tools of the Trade: Linux and SQL</td><td>Linux, Bash</td><td class="cdate">Jun 2025</td></tr>
      <tr><td class="cname">Google Prompting Essentials</td><td>AI, Problem Solving</td><td class="cdate">Aug 2025</td></tr>
      <tr><td class="cname">Hands-on Quantum Error Correction — Google Quantum AI</td><td>Quantum Computing</td><td class="cdate">Jun 2025</td></tr>
      <tr><td class="cname">Quantum Computing For Everyone — Fractal</td><td>Quantum Computing</td><td class="cdate">Mar 2025</td></tr>
      <tr><td class="cname">Crash Course on Python</td><td>Python, Algorithms</td><td class="cdate">Sep 2025</td></tr>
      <tr><td class="cname">Python Data Structures — University of Michigan</td><td>Data Structures</td><td class="cdate">Jun 2025</td></tr>
      <tr><td class="cname">Programming for Everybody — University of Michigan</td><td>Python</td><td class="cdate">Apr 2025</td></tr>
      <tr><td class="cname">Python for Data Science, AI & Development — IBM</td><td>Python</td><td class="cdate">Mar 2025</td></tr>
      <tr><td class="cname">AI For Everyone — DeepLearning.AI</td><td>Generative AI</td><td class="cdate">Mar 2025</td></tr>
      <tr><td class="cname">Ethical Hacking Foundations — Packt</td><td>Linux</td><td class="cdate">Jun 2025</td></tr>
      <tr><td class="cname">Rocket Science for Everyone — Yale University</td><td>Rocket Technology</td><td class="cdate">Mar 2025</td></tr>
      <tr><td class="cname">Workshop on GR, Cosmology, Astrophysics & Particle Physics — SARL</td><td>Astrophysics</td><td class="cdate">Dec 2024</td></tr>
      <tr><td class="cname">How to Write a Research Paper — HEC</td><td>Research Skills</td><td class="cdate">Feb 2025</td></tr>
      <tr><td class="cname">Work Smarter with MS Excel / PowerPoint — Microsoft</td><td>MS Office</td><td class="cdate">Mar 2025</td></tr>
    </table>
    <p class="cert-more">Full list with credential IDs available on request or via LinkedIn.</p>
  </div>
</section>

<div class="divider" aria-hidden="true">
  <div class="divider-track" id="divider4"></div>
</div>

<section class="section" id="contact">
  <div class="wrap contact-inner">
    <div class="eyebrow">Get in touch</div>
    <h2>Working on something in Space,<br>AI, ML, Automation or Security? Let's talk.</h2>
    <div class="contact-links">
      <a href="mailto:saifgillani3@gmail.com" class="btn btn-primary">saifgillani3@gmail.com</a>
      <a href="https://www.linkedin.com/in/syed-saif-gillani-309078296/" target="_blank" rel="noopener" class="btn btn-ghost">LinkedIn ↗</a>
      <a href="https://github.com/SyedSaif101" class="btn btn-ghost" id="github-link">GitHub ↗</a>
    </div>
  </div>
</section>

<footer>
  Syed Saif Gillani — Islamabad, Pakistan · Built & deployed as a static site.
</footer>

<script>
  // Tabs
  const tabs = document.querySelectorAll('.tab');
  const panels = document.querySelectorAll('.track-panel');
  tabs.forEach(tab => {
    tab.addEventListener('click', () => {
      tabs.forEach(t => { t.classList.remove('active'); t.setAttribute('aria-selected','false'); });
      panels.forEach(p => p.classList.remove('active'));
      tab.classList.add('active');
      tab.setAttribute('aria-selected','true');
      document.querySelector(`.track-panel[data-panel="${tab.dataset.track}"]`).classList.add('active');
    });
  });

  // Divider spectrum bars — deterministic pseudo-random heights so it reads as data, not decoration
  function seededRandom(seed){ let x = Math.sin(seed)*10000; return x - Math.floor(x); }
  document.querySelectorAll('.divider-track').forEach((track, ti) => {
    const barCount = 90;
    for(let i=0;i<barCount;i++){
      const bar = document.createElement('div');
      bar.className = 'divider-bar';
      const h = 4 + seededRandom(i*7.31 + ti*101) * 40;
      bar.style.height = h + 'px';
      const palette = ['#232B3B','#232B3B','#232B3B','#4FD1C5','#9C8FF0','#232B3B'];
      bar.style.background = palette[Math.floor(seededRandom(i*3.1+ti)*palette.length)];
      track.appendChild(bar);
    }
  });
</script>
</body>
</html>
