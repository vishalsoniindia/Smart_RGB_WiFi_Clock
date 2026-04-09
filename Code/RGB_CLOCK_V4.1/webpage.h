#pragma once
#include <pgmspace.h>

const char RGB_CLOCK_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RGB Clock Configuration</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.4.0/css/all.min.css">
    <style>
      :root {
        --primary-color: #8a2be2;
        --primary-dark: #6a1cb0;
        --bg-dark: #121212;
        --bg-card: #1e1e1e;
        --bg-card-light: #2a2a2a;
        --text-primary: #f0f0f0;
        --text-secondary: #b0b0b0;
        --border-color: #333;
        --success-color: #28a745;
        --danger-color: #dc3545;
        --warning-color: #ffc107;
        --toggle-off: #444;
        --shadow: rgba(0, 0, 0, 0.5);
        --transition: all 0.3s ease;
      }

      /* Light theme variables */
      .light-theme {
        --primary-color: #6a11cb;
        --primary-dark: #4a0ba3;
        --bg-dark: #f5f5f5;
        --bg-card: #ffffff;
        --bg-card-light: #f9f9f9;
        --text-primary: #222222;
        --text-secondary: #555555;
        --border-color: #ddd;
        --toggle-off: #ccc;
        --shadow: rgba(0, 0, 0, 0.1);
      }

      * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
      }

      body {
        background-color: var(--bg-dark);
        color: var(--text-primary);
        min-height: 100vh;
        transition: var(--transition);
        line-height: 1.6;
      }

      .container {
        max-width: 1200px;
        margin: 0 auto;
        padding: 20px;
      }

      /* Header */
      header {
        display: flex;
        justify-content: space-between;
        align-items: center;
        padding: 15px 0;
        margin-bottom: 30px;
        border-bottom: 1px solid var(--border-color);
      }

      .logo {
        display: flex;
        align-items: center;
        gap: 10px;
      }

      .logo-icon {
        color: var(--primary-color);
        font-size: 28px;
      }

      .logo-text {
        font-size: 24px;
        font-weight: 700;
        background: linear-gradient(to right, #8a2be2, #00bfff);
        -webkit-background-clip: text;
        background-clip: text;
        color: transparent;
      }

      /* Copyright line added below brand name */
      .copyright {
        font-size: 12px;
        color: var(--text-secondary);
        font-weight: 400;
        margin-top: 2px;
        letter-spacing: 0.5px;
      }

      .header-controls {
        display: flex;
        align-items: center;
        gap: 10px;
        font-size: 14px;
      }

      /* Theme toggle */
      .theme-toggle {
        position: relative;
        display: inline-block;
        width: 60px;
        height: 30px;
      }

      .theme-toggle input {
        opacity: 0;
        width: 0;
        height: 0;
      }

      .theme-slider {
        position: absolute;
        cursor: pointer;
        top: 0;
        left: 0;
        right: 0;
        bottom: 0;
        background-color: var(--toggle-off);
        transition: var(--transition);
        border-radius: 34px;
      }

      .theme-slider:before {
        position: absolute;
        content: "";
        height: 22px;
        width: 22px;
        left: 4px;
        bottom: 4px;
        background-color: white;
        transition: var(--transition);
        border-radius: 50%;
      }

      input:checked+.theme-slider {
        background-color: var(--primary-color);
      }

      input:checked+.theme-slider:before {
        transform: translateX(30px);
      }

      /* Buttons */
      .btn {
        padding: 10px 20px;
        border: none;
        border-radius: 8px;
        font-weight: 600;
        cursor: pointer;
        transition: var(--transition);
        display: inline-flex;
        align-items: center;
        justify-content: center;
        gap: 8px;
      }

      .btn-primary {
        background-color: var(--primary-color);
        color: white;
      }

      .btn-primary:hover {
        background-color: var(--primary-dark);
        transform: translateY(-2px);
        box-shadow: 0 5px 15px var(--shadow);
      }

      .btn-secondary {
        background-color: transparent;
        color: var(--text-primary);
        border: 1px solid var(--border-color);
      }

      .btn-secondary:hover {
        background-color: var(--bg-card-light);
      }

      .btn-small {
        padding: 8px 16px;
        font-size: 14px;
      }

      /* Menu Page */
      .menu-grid {
        display: grid;
        grid-template-columns: repeat(auto-fill, minmax(250px, 1fr));
        gap: 20px;
        margin-top: 30px;
      }

      .menu-card {
        background-color: var(--bg-card);
        border-radius: 12px;
        padding: 30px 20px;
        text-align: center;
        cursor: pointer;
        transition: var(--transition);
        border: 1px solid transparent;
      }

      .menu-card:hover {
        transform: translateY(-5px);
        border-color: var(--primary-color);
        box-shadow: 0 10px 20px var(--shadow);
      }

      .menu-icon {
        font-size: 48px;
        color: var(--primary-color);
        margin-bottom: 15px;
      }

      .menu-title {
        font-size: 22px;
        margin-bottom: 10px;
      }

      .menu-desc {
        color: var(--text-secondary);
        font-size: 14px;
      }

      /* Content Pages */
      .page {
        display: none;
        animation: fadeIn 0.5s ease;
      }

      .page.active {
        display: block;
      }

      @keyframes fadeIn {
        from {
          opacity: 0;
        }

        to {
          opacity: 1;
        }
      }

      .page-header {
        display: flex;
        justify-content: space-between;
        align-items: center;
        margin-bottom: 30px;
        padding-bottom: 15px;
        border-bottom: 1px solid var(--border-color);
      }

      .page-title {
        display: flex;
        align-items: center;
        gap: 10px;
        font-size: 28px;
      }

      .page-title i {
        color: var(--primary-color);
      }

      /* MODIFICATION 2: Added header buttons container */
      .page-header-buttons {
        display: flex;
        gap: 10px;
        align-items: center;
      }

      /* Form Styles */
      .form-container {
        background-color: var(--bg-card);
        border-radius: 12px;
        padding: 25px;
        margin-bottom: 30px;
        border: 1px solid var(--border-color);
      }

      .form-group {
        margin-bottom: 25px;
      }

      .form-label {
        display: block;
        margin-bottom: 10px;
        font-weight: 600;
        color: var(--text-primary);
      }

      .form-hint {
        font-size: 14px;
        color: var(--text-secondary);
        margin-top: 5px;
      }

      /* Custom Select - Updated with open class */
      .custom-select {
        position: relative;
        width: 100%;
        z-index: 1;
        /* base layer */
      }

      /* ADD this */
      .custom-select.open {
        z-index: 9999;
        /* bring active dropdown to front */
      }

      .select-selected {
        background-color: var(--bg-card-light);
        border-radius: 8px;
        padding: 14px 20px;
        cursor: pointer;
        border: 1px solid var(--border-color);
        transition: var(--transition);
        display: flex;
        justify-content: space-between;
        align-items: center;
        user-select: none;
      }

      .select-selected:after {
        content: "\f078";
        font-family: "Font Awesome 6 Free";
        font-weight: 900;
        transition: var(--transition);
      }

      .select-selected.active:after {
        transform: rotate(180deg);
      }

      .select-items {
        position: absolute;
        background-color: var(--bg-card-light);
        border-radius: 8px;
        top: 100%;
        left: 0;
        right: 0;
        z-index: 99;
        border: 1px solid var(--border-color);
        margin-top: 5px;
        max-height: 300px;
        /* Increased for timezone list */
        overflow-y: auto;
        display: none;
        box-shadow: 0 5px 15px var(--shadow);
      }

      .select-items.show {
        display: block;
      }

      .select-items div {
        padding: 12px 20px;
        cursor: pointer;
        transition: var(--transition);
      }

      .select-items div:hover {
        background-color: var(--primary-color);
        color: white;
      }

      /* Add selected option highlight */
      .select-items div.selected {
        background-color: var(--primary-dark);
        color: white;
      }

      /* Custom Toggle Switch */
      .toggle-container {
        display: flex;
        align-items: center;
        justify-content: space-between;
        margin-bottom: 15px;
      }

      .toggle-label {
        display: flex;
        flex-direction: column;
      }

      .toggle-switch {
        position: relative;
        display: inline-block;
        width: 60px;
        height: 30px;
      }

      .toggle-switch input {
        opacity: 0;
        width: 0;
        height: 0;
      }

      .toggle-slider {
        position: absolute;
        cursor: pointer;
        top: 0;
        left: 0;
        right: 0;
        bottom: 0;
        background-color: var(--toggle-off);
        transition: var(--transition);
        border-radius: 34px;
      }

      .toggle-slider:before {
        position: absolute;
        content: "";
        height: 22px;
        width: 22px;
        left: 4px;
        bottom: 4px;
        background-color: white;
        transition: var(--transition);
        border-radius: 50%;
      }

      input:checked+.toggle-slider {
        background-color: var(--primary-color);
      }

      input:checked+.toggle-slider:before {
        transform: translateX(30px);
      }

      /* Slider */
      .slider-container {
        margin-top: 20px;
      }

      .slider {
        -webkit-appearance: none;
        width: 100%;
        height: 10px;
        border-radius: 5px;
        background: var(--bg-card-light);
        outline: none;
      }

      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 24px;
        height: 24px;
        border-radius: 50%;
        background: var(--primary-color);
        cursor: pointer;
      }

      .slider::-moz-range-thumb {
        width: 24px;
        height: 24px;
        border-radius: 50%;
        background: var(--primary-color);
        cursor: pointer;
        border: none;
      }

      .slider-value {
        text-align: center;
        margin-top: 10px;
        font-weight: 600;
        color: var(--primary-color);
      }

      /* Alarm Section */
      .alarm-item {
        background-color: var(--bg-card-light);
        border-radius: 10px;
        padding: 20px;
        margin-bottom: 20px;
        border: 1px solid var(--border-color);
      }

      .alarm-header {
        display: flex;
        justify-content: space-between;
        align-items: center;
        margin-bottom: 15px;
      }

      .alarm-title {
        font-weight: 600;
        font-size: 18px;
      }

      .alarm-controls {
        display: flex;
        gap: 15px;
        margin-top: 20px;
        flex-wrap: wrap;
      }

      .progress-bar {
        width: 100%;
        height: 14px;
        background: #ddd;
        border-radius: 7px;
        overflow: hidden;
        margin-top: 10px;
      }

      .progress-bar div {
        height: 100%;
        width: 0%;
        background: #4caf50;
        transition: width 0.2s;
      }

      /* Time Selector - UPDATED to keep hour/min/AMPM in one line */
      .time-selector {
        display: flex;
        gap: 10px;
        align-items: center;
        flex-wrap: nowrap;
        /* Changed from wrap to nowrap */
      }

      .time-selector .custom-select {
        flex: 1;
        min-width: 80px;
      }

      .time-selector span {
        font-size: 18px;
        font-weight: bold;
        color: var(--text-primary);
        margin: 0 2px;
      }

      /* Footer */
      .footer-buttons {
        display: flex;
        justify-content: space-between;
        padding: 20px 0;
        border-top: 1px solid var(--border-color);
        margin-top: 30px;
      }

      .site-footer {
        width: 100%;
        text-align: center;
        padding: 15px 10px;
        font-size: 13px;
        color: var(--text-secondary);
        border-top: 1px solid var(--border-color);
        background-color: var(--bg-card);
      }

      /* Slightly smaller text on very small screens */
      @media (max-width: 480px) {
        .site-footer {
          font-size: 12px;
          padding: 12px 8px;
        }
      }

      @media (max-width: 768px) {
        .copyright {
          display: none;
        }
      }

      /* Responsive Design - FIXED adaptive ratio */
      @media (max-width: 768px) {
        .menu-grid {
          grid-template-columns: repeat(auto-fill, minmax(200px, 1fr));
        }

        .header-controls {
          flex-direction: row;
          align-items: center;
          gap: 15px;
        }

        .logo {
          flex-direction: row;
          align-items: center;
          gap: 10px;
        }

        .logo-text {
          font-size: 20px;
        }

        .copyright {
          display: none;
          /* Hide on mobile to save space */
        }

        .page-title {
          font-size: 22px;
        }

        .page-header {
          flex-direction: column;
          align-items: flex-start;
          gap: 15px;
        }

        .page-header-buttons {
          width: 100%;
          justify-content: space-between;
          flex-wrap: nowrap;
        }

        .alarm-controls {
          flex-direction: column;
        }

        .time-selector {
          flex-wrap: wrap;
          justify-content: flex-start;
        }

        .time-selector .custom-select {
          min-width: 70px;
          flex: 0 0 auto;
        }

        .footer-buttons {
          flex-direction: column;
          gap: 15px;
        }

        .footer-buttons .btn {
          width: 100%;
        }

        /* Form container adjustments */
        .form-container {
          padding: 20px 15px;
        }
      }

      @media (max-width: 480px) {
        .menu-grid {
          grid-template-columns: 1fr;
          gap: 15px;
        }

        .container {
          padding: 15px 10px;
        }

        .form-container {
          padding: 15px 10px;
        }

        .time-selector {
          gap: 5px;
          flex-wrap: wrap;
        }

        .time-selector .custom-select {
          min-width: 60px;
          flex: 1;
        }

        .page-header {
          margin-bottom: 20px;
        }

        .page-header-buttons {
          gap: 8px;
        }

        .page-header-buttons .btn {
          padding: 8px 12px;
          font-size: 13px;
        }

        .page-title {
          font-size: 20px;
        }

        header {
          flex-direction: column;
          align-items: flex-start;
          gap: 15px;
          padding: 10px 0;
          margin-bottom: 20px;
        }

        .header-controls {
          width: 100%;
          justify-content: space-between;
        }

        .logo {
          flex-direction: row;
          align-items: center;
          width: 100%;
          justify-content: space-between;
        }

        .logo-text {
          font-size: 18px;
        }

        .alarm-item {
          padding: 15px;
        }

        .alarm-title {
          font-size: 16px;
        }
      }

      /* ===== MOBILE LIST VIEW FOR MAIN MENU ONLY ===== */
      @media (max-width: 768px) {
        #menuPage .menu-grid {
          grid-template-columns: 1fr;
          gap: 12px;
        }

        #menuPage .menu-card {
          display: flex;
          align-items: center;
          text-align: left;
          padding: 16px;
          gap: 15px;
        }

        #menuPage .menu-icon {
          font-size: 32px;
          margin-bottom: 0;
          flex-shrink: 0;
        }

        #menuPage .menu-title {
          font-size: 18px;
          margin-bottom: 4px;
        }

        #menuPage .menu-desc {
          font-size: 13px;
        }
      }

      @media (max-width: 360px) {
        .container {
          padding: 10px 8px;
        }

        .menu-grid {
          gap: 10px;
        }

        .menu-card {
          padding: 20px 15px;
        }

        .menu-icon {
          font-size: 36px;
        }

        .menu-title {
          font-size: 18px;
        }

        .time-selector .custom-select {
          min-width: 50px;
        }

        .page-header-buttons .btn {
          padding: 6px 10px;
          font-size: 12px;
        }
      }

      /* WiFi/OTA Page */
      .feature-disabled {
        text-align: center;
        padding: 60px 20px;
        background-color: var(--bg-card-light);
        border-radius: 12px;
        border: 2px dashed var(--border-color);
      }

      .feature-disabled i {
        font-size: 72px;
        color: var(--text-secondary);
        margin-bottom: 20px;
      }

      .feature-disabled h3 {
        font-size: 28px;
        margin-bottom: 15px;
      }

      .feature-disabled p {
        color: var(--text-secondary);
        max-width: 500px;
        margin: 0 auto;
      }

      /* Conditional fields */
      .conditional-field {
        display: none;
        padding-left: 20px;
        border-left: 3px solid var(--primary-color);
        margin-top: 20px;
        animation: slideIn 0.3s ease;
      }

      @keyframes slideIn {
        from {
          opacity: 0;
          transform: translateX(-10px);
        }

        to {
          opacity: 1;
          transform: translateX(0);
        }
      }

      .conditional-field.show {
        display: block;
      }

      /* Status message */
      .status-message {
        position: fixed;
        top: 20px;
        right: 20px;
        padding: 15px 25px;
        border-radius: 8px;
        background-color: var(--success-color);
        color: white;
        font-weight: 600;
        box-shadow: 0 5px 15px var(--shadow);
        z-index: 1000;
        transform: translateX(150%);
        transition: transform 0.5s ease;
      }

      .status-message.show {
        transform: translateX(0);
      }

      .status-message.error {
        background-color: var(--danger-color);
      }

      /* Time selector container for theft detection */
      .theft-time-selector {
        margin-top: 15px;
      }

      .theft-time-selector .form-group {
        margin-bottom: 15px;
      }

      /* Search box for timezone */
      .timezone-search {
        margin-bottom: 10px;
        padding: 10px;
        width: 100%;
        border: 1px solid var(--border-color);
        border-radius: 8px;
        background-color: var(--bg-card-light);
        color: var(--text-primary);
      }

      .timezone-search:focus {
        outline: none;
        border-color: var(--primary-color);
      }
    </style>
  </head>
  <body>
    <div class="container">
      <header>
        <div class="logo">
          <i class="fas fa-clock logo-icon"></i>
          <span class="logo-text">RGB Clock Config</span>
        </div>
        <div class="header-controls">
          <span id="themeText" class="form-hint">Switch to Light</span>
          <label class="theme-toggle">
            <input type="checkbox" id="themeToggle">
            <span class="theme-slider"></span>
          </label>
        </div>
      </header>
      <!-- Menu Page -->
      <div id="menuPage" class="page active">
        <h1 class="page-title">
          <i class="fas fa-cog"></i> Configuration Menu
        </h1>
        <p style="color: var(--text-secondary); margin-bottom: 30px;"> Select a configuration category to customize your RGB clock settings </p>
        <div class="menu-grid">
          <div class="menu-card" data-page="clockPage">
            <i class="fas fa-clock menu-icon"></i>
            <h3 class="menu-title">Clock</h3>
            <p class="menu-desc">Configure timezone, display format, brightness and more</p>
          </div>
          <div class="menu-card" data-page="colorsPage">
            <i class="fas fa-palette menu-icon"></i>
            <h3 class="menu-title">Colors</h3>
            <p class="menu-desc">Set solid colors or choose from various lighting effects</p>
          </div>
          <div class="menu-card" data-page="alarmPage">
            <i class="fas fa-bell menu-icon"></i>
            <h3 class="menu-title">Alarm</h3>
            <p class="menu-desc">Set up to 5 different alarms with custom times</p>
          </div>
          <div class="menu-card" data-page="wifiPage">
            <i class="fas fa-wifi menu-icon"></i>
            <h3 class="menu-title">WiFi</h3>
            <p class="menu-desc">Configure WiFi connection settings</p>
          </div>
          <div class="menu-card" data-page="otaPage">
            <i class="fas fa-cloud-upload-alt menu-icon"></i>
            <h3 class="menu-title">OTA</h3>
            <p class="menu-desc">Over-the-air firmware updates</p>
          </div>
        </div>
      </div>
      <!-- Clock Configuration Page -->
      <div id="clockPage" class="page">
        <div class="page-header">
          <h2 class="page-title">
            <i class="fas fa-clock"></i> Clock Settings
          </h2>
          <!-- MODIFICATION 2: Added Save & Exit button in header -->
          <div class="page-header-buttons">
            <button class="btn btn-primary btn-small" id="saveExitClockTop">
              <i class="fas fa-save"></i> Save & Exit </button>
            <button class="btn btn-secondary btn-small" id="backToMenu">
              <i class="fas fa-arrow-left"></i> Back to Menu </button>
          </div>
        </div>
        <div class="form-container">
          <div class="form-group">
            <label class="form-label">Timezone Selection</label>
            <div class="custom-select">
              <div class="select-selected" id="timezoneSelect" data-value="Asia/Kolkata">India (GMT+5:30)</div>
              <div class="select-items" id="timezoneOptions">
                <!-- Timezones will be populated by JavaScript -->
              </div>
            </div>
            <div class="form-hint">Select your local timezone</div>
          </div>
          <div class="form-group">
            <label class="form-label">Time Mode</label>
            <div class="custom-select">
              <div class="select-selected" id="timeModeSelect" data-value="24">24 Hour Mode</div>
              <div class="select-items" id="timeModeOptions">
                <div data-value="24" class="selected">24 Hour Mode</div>
                <div data-value="12">12 Hour Mode</div>
              </div>
            </div>
          </div>
          <div class="toggle-container">
            <div class="toggle-label">
              <span>Auto Brightness Control</span>
              <span class="form-hint">Automatically adjust brightness based on ambient light</span>
            </div>
            <label class="toggle-switch">
              <input type="checkbox" id="autoBrightness">
              <span class="toggle-slider"></span>
            </label>
          </div>
          <div class="form-group conditional-field" id="brightnessSliderContainer">
            <label class="form-label">Brightness</label>
            <div class="slider-container">
              <input type="range" min="0" max="100" value="80" class="slider" id="brightnessSlider">
              <div class="slider-value">
                <span id="brightnessValue">80</span>%
              </div>
            </div>
          </div>
          <div class="form-group">
            <label class="form-label">Display Only</label>
            <div class="custom-select">
              <div class="select-selected" id="displayOnlySelect" data-value="all">All Rotate</div>
              <div class="select-items" id="displayOnlyOptions">
                <div data-value="all" class="selected">All Rotate</div>
                <div data-value="time">Time Only</div>
                <div data-value="temperature">Temperature Only</div>
                <div data-value="humidity">Humidity Only</div>
              </div>
            </div>
          </div>
          <div class="form-group conditional-field" id="rotateTimeContainer">
            <label class="form-label">Display Rotate Time</label>
            <div class="custom-select">
              <div class="select-selected" id="rotateTimeSelect" data-value="5">5 seconds</div>
              <div class="select-items" id="rotateTimeOptions">
                <!-- Will be populated by JavaScript -->
              </div>
            </div>
            <div class="form-hint">Time before display rotates to the next message</div>
          </div>
          <div class="toggle-container">
            <div class="toggle-label">
              <span>Power Saving Mode</span>
              <span class="form-hint">Display turns on only when motion is detected</span>
            </div>
            <label class="toggle-switch">
              <input type="checkbox" id="powerSaving">
              <span class="toggle-slider"></span>
            </label>
          </div>
          <!-- MODIFICATION 1: Added description to Set Display ON Time -->
          <div class="form-group conditional-field" id="displayOnTimeContainer">
            <label class="form-label">Set Display ON Time</label>
            <div class="custom-select">
              <div class="select-selected" id="displayOnTimeSelect" data-value="1">1 minute</div>
              <div class="select-items" id="displayOnTimeOptions">
                <!-- Will be populated by JavaScript -->
              </div>
            </div>
            <div class="form-hint">Display stays on till this time after motion detected</div>
          </div>
          <div class="toggle-container">
            <div class="toggle-label">
              <span>Theft Detection</span>
              <span class="form-hint">Play sound when motion is detected</span>
            </div>
            <label class="toggle-switch">
              <input type="checkbox" id="theftDetection">
              <span class="toggle-slider"></span>
            </label>
          </div>
          <div class="form-group conditional-field" id="theftSoundContainer">
            <label class="form-label">Theft Sound Timeout</label>
            <div class="custom-select">
              <div class="select-selected" id="theftSoundSelect" data-value="10">10 seconds</div>
              <div class="select-items" id="theftSoundOptions">
                <!-- Will be populated by JavaScript -->
              </div>
            </div>
            <div class="form-hint">Time until sound plays after motion detection</div>
          </div>
          <div class="form-group conditional-field" id="theftTimingContainer">
            <div class="toggle-container">
              <div class="toggle-label">
                <span>Set Theft Detection Timing</span>
                <span class="form-hint">Enable specific timing for theft detection</span>
              </div>
              <label class="toggle-switch">
                <input type="checkbox" id="theftTimingToggle">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <div class="conditional-field" id="theftTimeRangeContainer">
              <div class="theft-time-selector">
                <div class="form-group" style="margin-top: 20px;">
                  <label class="form-label">Start Theft Detect Timing</label>
                  <!-- MODIFICATION 2: All time selectors now in one line -->
                  <div class="time-selector">
                    <div class="custom-select">
                      <div class="select-selected" id="theftStartHour" data-value="11">11</div>
                      <div class="select-items" id="theftStartHourOptions">
                        <!-- Hours will be populated by JS -->
                      </div>
                    </div>
                    <span>:</span>
                    <div class="custom-select">
                      <div class="select-selected" id="theftStartMinute" data-value="00">00</div>
                      <div class="select-items" id="theftStartMinuteOptions">
                        <!-- Minutes will be populated by JS -->
                      </div>
                    </div>
                    <div class="custom-select">
                      <div class="select-selected" id="theftStartAmPm" data-value="PM">PM</div>
                      <div class="select-items">
                        <div>AM</div>
                        <div class="selected">PM</div>
                      </div>
                    </div>
                  </div>
                </div>
                <div class="form-group">
                  <label class="form-label">End Theft Detect Timing</label>
                  <!-- MODIFICATION 2: All time selectors now in one line -->
                  <div class="time-selector">
                    <div class="custom-select">
                      <div class="select-selected" id="theftEndHour" data-value="06">06</div>
                      <div class="select-items" id="theftEndHourOptions">
                        <!-- Hours will be populated by JS -->
                      </div>
                    </div>
                    <span>:</span>
                    <div class="custom-select">
                      <div class="select-selected" id="theftEndMinute" data-value="00">00</div>
                      <div class="select-items" id="theftEndMinuteOptions">
                        <!-- Minutes will be populated by JS -->
                      </div>
                    </div>
                    <div class="custom-select">
                      <div class="select-selected" id="theftEndAmPm" data-value="AM">AM</div>
                      <div class="select-items">
                        <div class="selected">AM</div>
                        <div>PM</div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
        <div class="footer-buttons">
          <button class="btn btn-secondary" id="backToMenuBottom">
            <i class="fas fa-arrow-left"></i> Back </button>
          <!-- MODIFICATION 1: Changed button text to "Save and Back" -->
          <button class="btn btn-primary" id="saveClock">
            <i class="fas fa-save"></i> Save and Back </button>
        </div>
      </div>
      <!-- Colors Configuration Page -->
      <div id="colorsPage" class="page">
        <div class="page-header">
          <h2 class="page-title">
            <i class="fas fa-palette"></i> Color Settings
          </h2>
          <div class="page-header-buttons">
            <button class="btn btn-primary btn-small" id="saveExitColorsTop">
              <i class="fas fa-save"></i> Save & Exit </button>
            <button class="btn btn-secondary btn-small" id="backToMenuColors">
              <i class="fas fa-arrow-left"></i> Back to Menu </button>
          </div>
        </div>
        <div class="form-container">
          <div class="form-group">
            <label class="form-label">Color Mode</label>
            <div class="custom-select">
              <div class="select-selected" id="colorModeSelect" data-value="solid">Solid</div>
              <div class="select-items" id="colorModeOptions">
                <div data-value="solid" class="selected">Solid</div>
                <div data-value="effect">Effect</div>
              </div>
            </div>
          </div>
          <div class="form-group conditional-field show" id="solidColorContainer">
            <label class="form-label">Choose Solid Color</label>
            <div class="custom-select">
              <div class="select-selected" id="solidColorSelect" data-value="red">Red</div>
              <div class="select-items" id="solidColorOptions">
                <!-- Solid colors will be populated by JavaScript -->
              </div>
            </div>
          </div>
          <div class="form-group conditional-field" id="effectContainer">
            <label class="form-label">Choose Effect</label>
            <div class="custom-select">
              <div class="select-selected" id="effectSelect" data-value="rainbow">Rainbow</div>
              <div class="select-items" id="effectOptions">
                <div data-value="rainbow" class="selected">Rainbow</div>
                <div data-value="pulse">Pulse</div>
                <div data-value="fade">Fade</div>
                <div data-value="chase">Chase</div>
                <div data-value="twinkle">Twinkle</div>
              </div>
            </div>
          </div>
          <div class="form-group" style="margin-top: 30px; text-align: center;">
            <button class="btn btn-primary" id="updateColors">
              <i class="fas fa-sync-alt"></i> Update Color Preview </button>
          </div>
        </div>
        <div class="footer-buttons">
          <button class="btn btn-secondary" id="backToMenuColorsBottom">
            <i class="fas fa-arrow-left"></i> Back </button>
          <!-- MODIFICATION 1: Changed button text to "Save and Back" -->
          <button class="btn btn-primary" id="saveColors">
            <i class="fas fa-save"></i> Save and Back </button>
        </div>
      </div>
      <!-- Alarm Configuration Page -->
      <div id="alarmPage" class="page">
        <div class="page-header">
          <h2 class="page-title">
            <i class="fas fa-bell"></i> Alarm Settings
          </h2>
          <div class="page-header-buttons">
            <button class="btn btn-primary btn-small" id="saveExitAlarmTop">
              <i class="fas fa-save"></i> Save & Exit </button>
            <button class="btn btn-secondary btn-small" id="backToMenuAlarm">
              <i class="fas fa-arrow-left"></i> Back to Menu </button>
          </div>
        </div>
        <div class="form-container">
          <p style="margin-bottom: 25px; color: var(--text-secondary);"> Configure up to 5 different alarms. Each alarm can be individually enabled or disabled. </p>
          <!-- Alarm 1 -->
          <div class="alarm-item">
            <div class="alarm-header">
              <div class="alarm-title">Alarm 1</div>
              <label class="toggle-switch">
                <input type="checkbox" class="alarm-toggle" data-alarm="1">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <!-- MODIFICATION 2: All time selectors now in one line -->
            <div class="time-selector">
              <div class="custom-select">
                <div class="select-selected alarm-hour" data-alarm="1" data-value="07">07</div>
                <div class="select-items alarm-hour-options" data-alarm="1">
                  <!-- Hours will be populated by JS -->
                </div>
              </div>
              <span>:</span>
              <div class="custom-select">
                <div class="select-selected alarm-minute" data-alarm="1" data-value="30">30</div>
                <div class="select-items alarm-minute-options" data-alarm="1">
                  <!-- Minutes will be populated by JS -->
                </div>
              </div>
              <div class="custom-select">
                <div class="select-selected alarm-ampm" data-alarm="1" data-value="AM">AM</div>
                <div class="select-items">
                  <div class="selected">AM</div>
                  <div>PM</div>
                </div>
              </div>
            </div>
            <div class="alarm-controls">
              <button class="btn btn-secondary btn-small alarm-audio-btn" data-alarm="1">
                <i class="fas fa-play-circle"></i> Play Audio </button>
            </div>
          </div>
          <!-- Alarm 2 -->
          <div class="alarm-item">
            <div class="alarm-header">
              <div class="alarm-title">Alarm 2</div>
              <label class="toggle-switch">
                <input type="checkbox" class="alarm-toggle" data-alarm="2">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <!-- MODIFICATION 2: All time selectors now in one line -->
            <div class="time-selector">
              <div class="custom-select">
                <div class="select-selected alarm-hour" data-alarm="2" data-value="08">08</div>
                <div class="select-items alarm-hour-options" data-alarm="2">
                  <!-- Hours will be populated by JS -->
                </div>
              </div>
              <span>:</span>
              <div class="custom-select">
                <div class="select-selected alarm-minute" data-alarm="2" data-value="00">00</div>
                <div class="select-items alarm-minute-options" data-alarm="2">
                  <!-- Minutes will be populated by JS -->
                </div>
              </div>
              <div class="custom-select">
                <div class="select-selected alarm-ampm" data-alarm="2" data-value="AM">AM</div>
                <div class="select-items">
                  <div class="selected">AM</div>
                  <div>PM</div>
                </div>
              </div>
            </div>
            <div class="alarm-controls">
              <button class="btn btn-secondary btn-small alarm-audio-btn" data-alarm="2">
                <i class="fas fa-play-circle"></i> Play Audio </button>
            </div>
          </div>
          <!-- Alarm 3 -->
          <div class="alarm-item">
            <div class="alarm-header">
              <div class="alarm-title">Alarm 3</div>
              <label class="toggle-switch">
                <input type="checkbox" class="alarm-toggle" data-alarm="3">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <!-- MODIFICATION 2: All time selectors now in one line -->
            <div class="time-selector">
              <div class="custom-select">
                <div class="select-selected alarm-hour" data-alarm="3" data-value="12">12</div>
                <div class="select-items alarm-hour-options" data-alarm="3">
                  <!-- Hours will be populated by JS -->
                </div>
              </div>
              <span>:</span>
              <div class="custom-select">
                <div class="select-selected alarm-minute" data-alarm="3" data-value="00">00</div>
                <div class="select-items alarm-minute-options" data-alarm="3">
                  <!-- Minutes will be populated by JS -->
                </div>
              </div>
              <div class="custom-select">
                <div class="select-selected alarm-ampm" data-alarm="3" data-value="PM">PM</div>
                <div class="select-items">
                  <div>AM</div>
                  <div class="selected">PM</div>
                </div>
              </div>
            </div>
            <div class="alarm-controls">
              <button class="btn btn-secondary btn-small alarm-audio-btn" data-alarm="3">
                <i class="fas fa-play-circle"></i> Play Audio </button>
            </div>
          </div>
          <!-- Alarm 4 -->
          <div class="alarm-item">
            <div class="alarm-header">
              <div class="alarm-title">Alarm 4</div>
              <label class="toggle-switch">
                <input type="checkbox" class="alarm-toggle" data-alarm="4">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <!-- MODIFICATION 2: All time selectors now in one line -->
            <div class="time-selector">
              <div class="custom-select">
                <div class="select-selected alarm-hour" data-alarm="4" data-value="06">06</div>
                <div class="select-items alarm-hour-options" data-alarm="4">
                  <!-- Hours will be populated by JS -->
                </div>
              </div>
              <span>:</span>
              <div class="custom-select">
                <div class="select-selected alarm-minute" data-alarm="4" data-value="45">45</div>
                <div class="select-items alarm-minute-options" data-alarm="4">
                  <!-- Minutes will be populated by JS -->
                </div>
              </div>
              <div class="custom-select">
                <div class="select-selected alarm-ampm" data-alarm="4" data-value="PM">PM</div>
                <div class="select-items">
                  <div>AM</div>
                  <div class="selected">PM</div>
                </div>
              </div>
            </div>
            <div class="alarm-controls">
              <button class="btn btn-secondary btn-small alarm-audio-btn" data-alarm="4">
                <i class="fas fa-play-circle"></i> Play Audio </button>
            </div>
          </div>
          <!-- Alarm 5 -->
          <div class="alarm-item">
            <div class="alarm-header">
              <div class="alarm-title">Alarm 5</div>
              <label class="toggle-switch">
                <input type="checkbox" class="alarm-toggle" data-alarm="5">
                <span class="toggle-slider"></span>
              </label>
            </div>
            <!-- MODIFICATION 2: All time selectors now in one line -->
            <div class="time-selector">
              <div class="custom-select">
                <div class="select-selected alarm-hour" data-alarm="5" data-value="10">10</div>
                <div class="select-items alarm-hour-options" data-alarm="5">
                  <!-- Hours will be populated by JS -->
                </div>
              </div>
              <span>:</span>
              <div class="custom-select">
                <div class="select-selected alarm-minute" data-alarm="5" data-value="15">15</div>
                <div class="select-items alarm-minute-options" data-alarm="5">
                  <!-- Minutes will be populated by JS -->
                </div>
              </div>
              <div class="custom-select">
                <div class="select-selected alarm-ampm" data-alarm="5" data-value="PM">PM</div>
                <div class="select-items">
                  <div>AM</div>
                  <div class="selected">PM</div>
                </div>
              </div>
            </div>
            <div class="alarm-controls">
              <button class="btn btn-secondary btn-small alarm-audio-btn" data-alarm="5">
                <i class="fas fa-play-circle"></i> Play Audio </button>
            </div>
          </div>
        </div>
        <div class="footer-buttons">
          <button class="btn btn-secondary" id="backToMenuAlarmBottom">
            <i class="fas fa-arrow-left"></i> Back </button>
          <!-- MODIFICATION 1: Changed button text to "Save and Back" -->
          <button class="btn btn-primary" id="saveAlarms">
            <i class="fas fa-save"></i> Save and Back </button>
        </div>
      </div>
      <!-- WiFi Configuration Page -->
      <div id="wifiPage" class="page">
        <div class="page-header">
          <h2 class="page-title">
            <i class="fas fa-wifi"></i> WiFi Settings
          </h2>
          <div class="page-header-buttons">
            <button class="btn btn-primary btn-small" id="saveExitWifiTop">
              <i class="fas fa-save"></i> Save & Exit </button>
            <button class="btn btn-secondary btn-small" id="backToMenuWifi">
              <i class="fas fa-arrow-left"></i> Back to Menu </button>
          </div>
        </div>

<div class="form-container">

  <!-- WiFi Status -->
  <div class="form-group">
    <label class="form-label">WiFi Status</label>
    <div id="wifiStatus" class="form-hint">
      Checking connection...
    </div>
  </div>

  <!-- Connected SSID -->
  <div class="form-group">
    <label class="form-label">Connected SSID</label>
    <input
      type="text"
      id="wifiSSID"
      class="timezone-search"
      placeholder="Enter WiFi SSID"
    >
        </div>

        <!-- Password with eye toggle -->
        <div class="form-group">
          <label class="form-label">WiFi Password</label>
          <div style="position: relative;">
            <input
              type="password"
              id="wifiPassword"
              class="timezone-search"
              placeholder="Enter WiFi Password"
            >

            <i
              id="toggleWifiPassword"
              class="fas fa-eye"
              style="
                position:absolute;
                right:12px;
                top:50%;
                transform:translateY(-50%);
                cursor:pointer;
                color:var(--text-secondary);
              ">
            </i>
          </div>
          <div class="form-hint">
            Password stored on device
          </div>
        </div>

      </div>
        <div class="footer-buttons">
          <button class="btn btn-secondary" id="backToMenuWifiBottom">
            <i class="fas fa-arrow-left"></i> Back </button>
          <button class="btn btn-primary" id="saveWifi">
            <i class="fas fa-save"></i> Save and Back
          </button>
        </div>
      </div>
      </div> <!-- ✅ CLOSE wifiPage -->

            <!-- OTA Configuration Page -->
      <div id="otaPage" class="page">
        <div class="page-header">
          <h2 class="page-title">
            <i class="fas fa-cloud-upload-alt"></i> OTA Update
          </h2>
          <div class="page-header-buttons">
            <button class="btn btn-secondary btn-small" id="backToMenuOTA">
              <i class="fas fa-arrow-left"></i> Back to Menu
            </button>
          </div>
        </div>

        <div class="form-container">
          <div class="form-group">
            <label class="form-label">Current Firmware Version</label>
            <div class="form-hint">
              <strong id="fwVersion">–</strong>
            </div>
          </div>

          <div class="form-group">
            <label class="form-label">Select Firmware (.bin)</label>
            <input type="file" id="otaFile" accept=".bin" class="timezone-search">
          </div>

          <div class="form-group">
            <button class="btn btn-primary" id="startOtaBtn">
              <i class="fas fa-upload"></i> Upload Firmware
            </button>
          </div>

          <div class="progress-bar">
            <div id="otaProgress"></div>
          </div>

          <p id="otaStatus" class="form-hint"></p>

          <button
            id="otaHomeBtn"
            class="btn btn-secondary"
            style="display:none"
            onclick="location.href='/'">
            Go Home
          </button>
        </div>
      </div>

      <!-- Status Message -->
      <div id="statusMessage" class="status-message"> Settings saved successfully! </div>
    </div>

    <script>
      // DOM elements
      const themeToggle = document.getElementById('themeToggle');
      const themeText = document.getElementById('themeText');
      const brightnessSlider = document.getElementById('brightnessSlider');
      const brightnessValue = document.getElementById('brightnessValue');
      const statusMessage = document.getElementById('statusMessage');
      
      // Global variables
      let saveClock, saveColors, saveAlarms, updateColors;
      
      // Theme toggle
      themeToggle.addEventListener('change', function() {
        const isLight = this.checked;
        document.body.classList.toggle('light-theme', isLight);
        localStorage.setItem('theme', isLight ? 'light' : 'dark');
        themeText.textContent = isLight ? 'Switch to Dark' : 'Switch to Light';
      });
      
      // Initial theme
      const savedTheme = localStorage.getItem('theme');
      if (savedTheme === 'dark') {
        themeToggle.checked = true;
        document.body.classList.add('light-theme');
        themeText.textContent = 'Switch to Dark';
      }
      
      // Brightness slider
      if (brightnessSlider && brightnessValue) {
        brightnessSlider.addEventListener('input', function() {
          brightnessValue.textContent = this.value;
        });
      }
      
      // Navigation between pages
      function setupNavigation() {
        // Menu card clicks
        document.querySelectorAll('.menu-card').forEach(card => {
          card.addEventListener('click', function() {
            const pageId = this.getAttribute('data-page');
            showPage(pageId);
          });
        });
        
        // Back to menu buttons
        const backButtons = ['backToMenu', 'backToMenuBottom', 'backToMenuColors', 
                            'backToMenuColorsBottom', 'backToMenuAlarm', 'backToMenuAlarmBottom', 
                            'backToMenuWifi', 'backToMenuWifiBottom', 'backToMenuOTA', 'backToMenuOTABottom'];
        
        backButtons.forEach(buttonId => {
          const button = document.getElementById(buttonId);
          if (button) {
            button.addEventListener('click', () => {
              showPage('menuPage');
            });
          }
        });
      }
      
      // Function to show specific page
      function showPage(pageId) {
        document.querySelectorAll('.page').forEach(p => p.classList.remove('active'));
        document.getElementById(pageId).classList.add('active');

        // 🔥 IMPORTANT
        if (pageId === 'wifiPage') {
          loadWifiStatus();
        }
      }
      
      // Save and exit function
      function saveAndExit() {
        showStatusMessage('Settings saved successfully! All changes have been applied to your RGB clock.', 'success');
        setTimeout(() => {
          showPage('menuPage');
        }, 1500);
      }
      
      // Status message display
      function showStatusMessage(message, type = 'success') {
        if (!statusMessage) return;
        statusMessage.textContent = message;
        statusMessage.className = 'status-message';
        statusMessage.classList.add(type);
        statusMessage.classList.add('show');
        setTimeout(() => {
          statusMessage.classList.remove('show');
        }, 3000);
      }
      
      // UPDATED DROPDOWN FUNCTIONALITY with toggle behavior and scroll
      function setupDropdowns() {
        document.addEventListener('click', function(e) {
          /* ================= CLICK ON SELECTED ================= */
          const selected = e.target.closest('.select-selected');
          if (selected) {
            e.stopPropagation();
            const dropdown = selected.parentElement;
            const options = dropdown.querySelector('.select-items');
            const isOpen = options.classList.contains('show');
            
            /* Close all dropdowns first */
            document.querySelectorAll('.select-items').forEach(el => el.classList.remove('show'));
            document.querySelectorAll('.select-selected').forEach(el => el.classList.remove('active'));
            document.querySelectorAll('.custom-select').forEach(el => el.classList.remove('open'));
            
            /* TOGGLE behavior */
            if (!isOpen) {
              options.classList.add('show');
              selected.classList.add('active');
              dropdown.classList.add('open');
              
              /* Highlight selected option */
              const selectedValue = selected.dataset.value || selected.textContent.trim();
              let selectedOption = null;
              options.querySelectorAll('div').forEach(opt => {
                opt.classList.remove('selected');
                const val = opt.dataset.value || opt.textContent.trim();
                if (val === selectedValue) {
                  opt.classList.add('selected');
                  selectedOption = opt;
                }
              });
              
              /* Scroll to selected option */
              if (selectedOption) {
                selectedOption.scrollIntoView({
                  block: 'nearest'
                });
              }
            }
            return;
          }
          
          /* ================= CLICK ON OPTION ================= */
          const option = e.target.closest('.select-items div');
          if (option) {
            const options = option.parentElement;
            const selected = options.previousElementSibling;
            const dropdown = selected.parentElement;
            selected.textContent = option.textContent;
            if (option.dataset.value) {
              selected.dataset.value = option.dataset.value;
            }
            options.classList.remove('show');
            selected.classList.remove('active');
            dropdown.classList.remove('open');
            handleConditionalFields();
            return;
          }
          
          /* ================= CLICK OUTSIDE ================= */
          document.querySelectorAll('.select-items').forEach(el => el.classList.remove('show'));
          document.querySelectorAll('.select-selected').forEach(el => el.classList.remove('active'));
          document.querySelectorAll('.custom-select').forEach(el => el.classList.remove('open'));
        });
      }
      
      // Toggle switch functionality for conditional fields
      function handleConditionalFields() {
        // Auto brightness toggle
        const autoBrightness = document.getElementById('autoBrightness');
        const brightnessSliderContainer = document.getElementById('brightnessSliderContainer');
        if (autoBrightness && brightnessSliderContainer) {
          if (autoBrightness.checked) {
            brightnessSliderContainer.classList.remove('show');
          } else {
            brightnessSliderContainer.classList.add('show');
          }
        }
        
        // Display rotate time
        const displayOnlySelect = document.getElementById('displayOnlySelect');
        const rotateTimeContainer = document.getElementById('rotateTimeContainer');
        if (displayOnlySelect && rotateTimeContainer) {
          const displayOnlyValue = displayOnlySelect.getAttribute('data-value') || displayOnlySelect.textContent.toLowerCase();
          if (displayOnlyValue.includes('all')) {
            rotateTimeContainer.classList.add('show');
          } else {
            rotateTimeContainer.classList.remove('show');
          }
        }
        
        // Power saving mode
        const powerSaving = document.getElementById('powerSaving');
        const displayOnTimeContainer = document.getElementById('displayOnTimeContainer');
        if (powerSaving && displayOnTimeContainer) {
          if (powerSaving.checked) {
            displayOnTimeContainer.classList.add('show');
          } else {
            displayOnTimeContainer.classList.remove('show');
          }
        }
        
        // Theft detection
        const theftDetection = document.getElementById('theftDetection');
        const theftSoundContainer = document.getElementById('theftSoundContainer');
        const theftTimingContainer = document.getElementById('theftTimingContainer');
        if (theftDetection && theftSoundContainer && theftTimingContainer) {
          if (theftDetection.checked) {
            theftSoundContainer.classList.add('show');
            theftTimingContainer.classList.add('show');
          } else {
            theftSoundContainer.classList.remove('show');
            theftTimingContainer.classList.remove('show');
          }
        }
        
        // Theft timing toggle
        const theftTimingToggle = document.getElementById('theftTimingToggle');
        const theftTimeRangeContainer = document.getElementById('theftTimeRangeContainer');
        if (theftTimingToggle && theftTimeRangeContainer) {
          if (theftTimingToggle.checked) {
            theftTimeRangeContainer.classList.add('show');
          } else {
            theftTimeRangeContainer.classList.remove('show');
          }
        }
        
        // Color mode
        const colorModeSelect = document.getElementById('colorModeSelect');
        const solidColorContainer = document.getElementById('solidColorContainer');
        const effectContainer = document.getElementById('effectContainer');
        if (colorModeSelect && solidColorContainer && effectContainer) {
          const colorModeValue = colorModeSelect.getAttribute('data-value') || colorModeSelect.textContent.toLowerCase();
          if (colorModeValue === 'solid') {
            solidColorContainer.classList.add('show');
            effectContainer.classList.remove('show');
          } else if (colorModeValue === 'effect') {
            solidColorContainer.classList.remove('show');
            effectContainer.classList.add('show');
          }
        }
      }
      
      // Initialize toggle event listeners
      function setupToggleListeners() {
        document.querySelectorAll('.toggle-switch input').forEach(toggle => {
          toggle.addEventListener('change', handleConditionalFields);
        });
      }
      
      // Complete timezone list matching ESP32 database
      const timezones = [
        { value: "Africa/Abidjan", name: "Africa - Abidjan" },
        { value: "Africa/Accra", name: "Africa - Accra" },
        { value: "Africa/Addis_Ababa", name: "Africa - Addis Ababa" },
        { value: "Africa/Algiers", name: "Africa - Algiers" },
        { value: "Africa/Asmara", name: "Africa - Asmara" },
        { value: "Africa/Bamako", name: "Africa - Bamako" },
        { value: "Africa/Bangui", name: "Africa - Bangui" },
        { value: "Africa/Banjul", name: "Africa - Banjul" },
        { value: "Africa/Bissau", name: "Africa - Bissau" },
        { value: "Africa/Blantyre", name: "Africa - Blantyre" },
        { value: "Africa/Brazzaville", name: "Africa - Brazzaville" },
        { value: "Africa/Bujumbura", name: "Africa - Bujumbura" },
        { value: "Africa/Cairo", name: "Africa - Cairo" },
        { value: "Africa/Casablanca", name: "Africa - Casablanca" },
        { value: "Africa/Ceuta", name: "Africa - Ceuta" },
        { value: "Africa/Conakry", name: "Africa - Conakry" },
        { value: "Africa/Dakar", name: "Africa - Dakar" },
        { value: "Africa/Dar_es_Salaam", name: "Africa - Dar es Salaam" },
        { value: "Africa/Djibouti", name: "Africa - Djibouti" },
        { value: "Africa/Douala", name: "Africa - Douala" },
        { value: "Africa/El_Aaiun", name: "Africa - El Aaiun" },
        { value: "Africa/Freetown", name: "Africa - Freetown" },
        { value: "Africa/Gaborone", name: "Africa - Gaborone" },
        { value: "Africa/Harare", name: "Africa - Harare" },
        { value: "Africa/Johannesburg", name: "Africa - Johannesburg" },
        { value: "Africa/Juba", name: "Africa - Juba" },
        { value: "Africa/Kampala", name: "Africa - Kampala" },
        { value: "Africa/Khartoum", name: "Africa - Khartoum" },
        { value: "Africa/Kigali", name: "Africa - Kigali" },
        { value: "Africa/Kinshasa", name: "Africa - Kinshasa" },
        { value: "Africa/Lagos", name: "Africa - Lagos" },
        { value: "Africa/Libreville", name: "Africa - Libreville" },
        { value: "Africa/Lome", name: "Africa - Lome" },
        { value: "Africa/Luanda", name: "Africa - Luanda" },
        { value: "Africa/Lubumbashi", name: "Africa - Lubumbashi" },
        { value: "Africa/Lusaka", name: "Africa - Lusaka" },
        { value: "Africa/Malabo", name: "Africa - Malabo" },
        { value: "Africa/Maputo", name: "Africa - Maputo" },
        { value: "Africa/Maseru", name: "Africa - Maseru" },
        { value: "Africa/Mbabane", name: "Africa - Mbabane" },
        { value: "Africa/Mogadishu", name: "Africa - Mogadishu" },
        { value: "Africa/Monrovia", name: "Africa - Monrovia" },
        { value: "Africa/Nairobi", name: "Africa - Nairobi" },
        { value: "Africa/Ndjamena", name: "Africa - Ndjamena" },
        { value: "Africa/Niamey", name: "Africa - Niamey" },
        { value: "Africa/Nouakchott", name: "Africa - Nouakchott" },
        { value: "Africa/Ouagadougou", name: "Africa - Ouagadougou" },
        { value: "Africa/Porto-Novo", name: "Africa - Porto-Novo" },
        { value: "Africa/Sao_Tome", name: "Africa - Sao Tome" },
        { value: "Africa/Tripoli", name: "Africa - Tripoli" },
        { value: "Africa/Tunis", name: "Africa - Tunis" },
        { value: "Africa/Windhoek", name: "Africa - Windhoek" },
        { value: "America/Adak", name: "America - Adak" },
        { value: "America/Anchorage", name: "America - Anchorage" },
        { value: "America/Anguilla", name: "America - Anguilla" },
        { value: "America/Antigua", name: "America - Antigua" },
        { value: "America/Araguaina", name: "America - Araguaina" },
        { value: "America/Argentina/Buenos_Aires", name: "America - Argentina/Buenos Aires" },
        { value: "America/Argentina/Catamarca", name: "America - Argentina/Catamarca" },
        { value: "America/Argentina/Cordoba", name: "America - Argentina/Cordoba" },
        { value: "America/Argentina/Jujuy", name: "America - Argentina/Jujuy" },
        { value: "America/Argentina/La_Rioja", name: "America - Argentina/La Rioja" },
        { value: "America/Argentina/Mendoza", name: "America - Argentina/Mendoza" },
        { value: "America/Argentina/Rio_Gallegos", name: "America - Argentina/Rio Gallegos" },
        { value: "America/Argentina/Salta", name: "America - Argentina/Salta" },
        { value: "America/Argentina/San_Juan", name: "America - Argentina/San Juan" },
        { value: "America/Argentina/San_Luis", name: "America - Argentina/San Luis" },
        { value: "America/Argentina/Tucuman", name: "America - Argentina/Tucuman" },
        { value: "America/Argentina/Ushuaia", name: "America - Argentina/Ushuaia" },
        { value: "America/Aruba", name: "America - Aruba" },
        { value: "America/Asuncion", name: "America - Asuncion" },
        { value: "America/Atikokan", name: "America - Atikokan" },
        { value: "America/Bahia", name: "America - Bahia" },
        { value: "America/Bahia_Banderas", name: "America - Bahia Banderas" },
        { value: "America/Barbados", name: "America - Barbados" },
        { value: "America/Belem", name: "America - Belem" },
        { value: "America/Belize", name: "America - Belize" },
        { value: "America/Blanc-Sablon", name: "America - Blanc-Sablon" },
        { value: "America/Boa_Vista", name: "America - Boa Vista" },
        { value: "America/Bogota", name: "America - Bogota" },
        { value: "America/Boise", name: "America - Boise" },
        { value: "America/Cambridge_Bay", name: "America - Cambridge Bay" },
        { value: "America/Campo_Grande", name: "America - Campo Grande" },
        { value: "America/Cancun", name: "America - Cancun" },
        { value: "America/Caracas", name: "America - Caracas" },
        { value: "America/Cayenne", name: "America - Cayenne" },
        { value: "America/Cayman", name: "America - Cayman" },
        { value: "America/Chicago", name: "America - Chicago" },
        { value: "America/Chihuahua", name: "America - Chihuahua" },
        { value: "America/Costa_Rica", name: "America - Costa Rica" },
        { value: "America/Creston", name: "America - Creston" },
        { value: "America/Cuiaba", name: "America - Cuiaba" },
        { value: "America/Curacao", name: "America - Curacao" },
        { value: "America/Danmarkshavn", name: "America - Danmarkshavn" },
        { value: "America/Dawson", name: "America - Dawson" },
        { value: "America/Dawson_Creek", name: "America - Dawson Creek" },
        { value: "America/Denver", name: "America - Denver" },
        { value: "America/Detroit", name: "America - Detroit" },
        { value: "America/Dominica", name: "America - Dominica" },
        { value: "America/Edmonton", name: "America - Edmonton" },
        { value: "America/Eirunepe", name: "America - Eirunepe" },
        { value: "America/El_Salvador", name: "America - El Salvador" },
        { value: "America/Fort_Nelson", name: "America - Fort Nelson" },
        { value: "America/Fortaleza", name: "America - Fortaleza" },
        { value: "America/Glace_Bay", name: "America - Glace Bay" },
        { value: "America/Godthab", name: "America - Godthab" },
        { value: "America/Goose_Bay", name: "America - Goose Bay" },
        { value: "America/Grand_Turk", name: "America - Grand Turk" },
        { value: "America/Grenada", name: "America - Grenada" },
        { value: "America/Guadeloupe", name: "America - Guadeloupe" },
        { value: "America/Guatemala", name: "America - Guatemala" },
        { value: "America/Guayaquil", name: "America - Guayaquil" },
        { value: "America/Guyana", name: "America - Guyana" },
        { value: "America/Halifax", name: "America - Halifax" },
        { value: "America/Havana", name: "America - Havana" },
        { value: "America/Hermosillo", name: "America - Hermosillo" },
        { value: "America/Indiana/Indianapolis", name: "America - Indiana/Indianapolis" },
        { value: "America/Indiana/Knox", name: "America - Indiana/Knox" },
        { value: "America/Indiana/Marengo", name: "America - Indiana/Marengo" },
        { value: "America/Indiana/Petersburg", name: "America - Indiana/Petersburg" },
        { value: "America/Indiana/Tell_City", name: "America - Indiana/Tell City" },
        { value: "America/Indiana/Vevay", name: "America - Indiana/Vevay" },
        { value: "America/Indiana/Vincennes", name: "America - Indiana/Vincennes" },
        { value: "America/Indiana/Winamac", name: "America - Indiana/Winamac" },
        { value: "America/Inuvik", name: "America - Inuvik" },
        { value: "America/Iqaluit", name: "America - Iqaluit" },
        { value: "America/Jamaica", name: "America - Jamaica" },
        { value: "America/Juneau", name: "America - Juneau" },
        { value: "America/Kentucky/Louisville", name: "America - Kentucky/Louisville" },
        { value: "America/Kentucky/Monticello", name: "America - Kentucky/Monticello" },
        { value: "America/Kralendijk", name: "America - Kralendijk" },
        { value: "America/La_Paz", name: "America - La Paz" },
        { value: "America/Lima", name: "America - Lima" },
        { value: "America/Los_Angeles", name: "America - Los Angeles" },
        { value: "America/Lower_Princes", name: "America - Lower Princes" },
        { value: "America/Maceio", name: "America - Maceio" },
        { value: "America/Managua", name: "America - Managua" },
        { value: "America/Manaus", name: "America - Manaus" },
        { value: "America/Marigot", name: "America - Marigot" },
        { value: "America/Martinique", name: "America - Martinique" },
        { value: "America/Matamoros", name: "America - Matamoros" },
        { value: "America/Mazatlan", name: "America - Mazatlan" },
        { value: "America/Menominee", name: "America - Menominee" },
        { value: "America/Merida", name: "America - Merida" },
        { value: "America/Metlakatla", name: "America - Metlakatla" },
        { value: "America/Mexico_City", name: "America - Mexico City" },
        { value: "America/Miquelon", name: "America - Miquelon" },
        { value: "America/Moncton", name: "America - Moncton" },
        { value: "America/Monterrey", name: "America - Monterrey" },
        { value: "America/Montevideo", name: "America - Montevideo" },
        { value: "America/Montreal", name: "America - Montreal" },
        { value: "America/Montserrat", name: "America - Montserrat" },
        { value: "America/Nassau", name: "America - Nassau" },
        { value: "America/New_York", name: "America - New York" },
        { value: "America/Nipigon", name: "America - Nipigon" },
        { value: "America/Nome", name: "America - Nome" },
        { value: "America/Noronha", name: "America - Noronha" },
        { value: "America/North_Dakota/Beulah", name: "America - North Dakota/Beulah" },
        { value: "America/North_Dakota/Center", name: "America - North Dakota/Center" },
        { value: "America/North_Dakota/New_Salem", name: "America - North Dakota/New Salem" },
        { value: "America/Nuuk", name: "America - Nuuk" },
        { value: "America/Ojinaga", name: "America - Ojinaga" },
        { value: "America/Panama", name: "America - Panama" },
        { value: "America/Pangnirtung", name: "America - Pangnirtung" },
        { value: "America/Paramaribo", name: "America - Paramaribo" },
        { value: "America/Phoenix", name: "America - Phoenix" },
        { value: "America/Port-au-Prince", name: "America - Port-au-Prince" },
        { value: "America/Port_of_Spain", name: "America - Port of Spain" },
        { value: "America/Porto_Velho", name: "America - Porto Velho" },
        { value: "America/Puerto_Rico", name: "America - Puerto Rico" },
        { value: "America/Punta_Arenas", name: "America - Punta Arenas" },
        { value: "America/Rainy_River", name: "America - Rainy River" },
        { value: "America/Rankin_Inlet", name: "America - Rankin Inlet" },
        { value: "America/Recife", name: "America - Recife" },
        { value: "America/Regina", name: "America - Regina" },
        { value: "America/Resolute", name: "America - Resolute" },
        { value: "America/Rio_Branco", name: "America - Rio Branco" },
        { value: "America/Santarem", name: "America - Santarem" },
        { value: "America/Santiago", name: "America - Santiago" },
        { value: "America/Santo_Domingo", name: "America - Santo Domingo" },
        { value: "America/Sao_Paulo", name: "America - Sao Paulo" },
        { value: "America/Scoresbysund", name: "America - Scoresbysund" },
        { value: "America/Sitka", name: "America - Sitka" },
        { value: "America/St_Barthelemy", name: "America - St Barthelemy" },
        { value: "America/St_Johns", name: "America - St Johns" },
        { value: "America/St_Kitts", name: "America - St Kitts" },
        { value: "America/St_Lucia", name: "America - St Lucia" },
        { value: "America/St_Thomas", name: "America - St Thomas" },
        { value: "America/St_Vincent", name: "America - St Vincent" },
        { value: "America/Swift_Current", name: "America - Swift Current" },
        { value: "America/Tegucigalpa", name: "America - Tegucigalpa" },
        { value: "America/Thule", name: "America - Thule" },
        { value: "America/Thunder_Bay", name: "America - Thunder Bay" },
        { value: "America/Tijuana", name: "America - Tijuana" },
        { value: "America/Toronto", name: "America - Toronto" },
        { value: "America/Tortola", name: "America - Tortola" },
        { value: "America/Vancouver", name: "America - Vancouver" },
        { value: "America/Whitehorse", name: "America - Whitehorse" },
        { value: "America/Winnipeg", name: "America - Winnipeg" },
        { value: "America/Yakutat", name: "America - Yakutat" },
        { value: "America/Yellowknife", name: "America - Yellowknife" },
        { value: "Antarctica/Casey", name: "Antarctica - Casey" },
        { value: "Antarctica/Davis", name: "Antarctica - Davis" },
        { value: "Antarctica/DumontDUrville", name: "Antarctica - Dumont DUrville" },
        { value: "Antarctica/Macquarie", name: "Antarctica - Macquarie" },
        { value: "Antarctica/Mawson", name: "Antarctica - Mawson" },
        { value: "Antarctica/McMurdo", name: "Antarctica - McMurdo" },
        { value: "Antarctica/Palmer", name: "Antarctica - Palmer" },
        { value: "Antarctica/Rothera", name: "Antarctica - Rothera" },
        { value: "Antarctica/Syowa", name: "Antarctica - Syowa" },
        { value: "Antarctica/Troll", name: "Antarctica - Troll" },
        { value: "Antarctica/Vostok", name: "Antarctica - Vostok" },
        { value: "Arctic/Longyearbyen", name: "Arctic - Longyearbyen" },
        { value: "Asia/Aden", name: "Asia - Aden" },
        { value: "Asia/Almaty", name: "Asia - Almaty" },
        { value: "Asia/Amman", name: "Asia - Amman" },
        { value: "Asia/Anadyr", name: "Asia - Anadyr" },
        { value: "Asia/Aqtau", name: "Asia - Aqtau" },
        { value: "Asia/Aqtobe", name: "Asia - Aqtobe" },
        { value: "Asia/Ashgabat", name: "Asia - Ashgabat" },
        { value: "Asia/Atyrau", name: "Asia - Atyrau" },
        { value: "Asia/Baghdad", name: "Asia - Baghdad" },
        { value: "Asia/Bahrain", name: "Asia - Bahrain" },
        { value: "Asia/Baku", name: "Asia - Baku" },
        { value: "Asia/Bangkok", name: "Asia - Bangkok" },
        { value: "Asia/Barnaul", name: "Asia - Barnaul" },
        { value: "Asia/Beirut", name: "Asia - Beirut" },
        { value: "Asia/Bishkek", name: "Asia - Bishkek" },
        { value: "Asia/Brunei", name: "Asia - Brunei" },
        { value: "Asia/Chita", name: "Asia - Chita" },
        { value: "Asia/Choibalsan", name: "Asia - Choibalsan" },
        { value: "Asia/Colombo", name: "Asia - Colombo" },
        { value: "Asia/Damascus", name: "Asia - Damascus" },
        { value: "Asia/Dhaka", name: "Asia - Dhaka" },
        { value: "Asia/Dili", name: "Asia - Dili" },
        { value: "Asia/Dubai", name: "Asia - Dubai" },
        { value: "Asia/Dushanbe", name: "Asia - Dushanbe" },
        { value: "Asia/Famagusta", name: "Asia - Famagusta" },
        { value: "Asia/Gaza", name: "Asia - Gaza" },
        { value: "Asia/Hebron", name: "Asia - Hebron" },
        { value: "Asia/Ho_Chi_Minh", name: "Asia - Ho Chi Minh" },
        { value: "Asia/Hong_Kong", name: "Asia - Hong Kong" },
        { value: "Asia/Hovd", name: "Asia - Hovd" },
        { value: "Asia/Irkutsk", name: "Asia - Irkutsk" },
        { value: "Asia/Jakarta", name: "Asia - Jakarta" },
        { value: "Asia/Jayapura", name: "Asia - Jayapura" },
        { value: "Asia/Jerusalem", name: "Asia - Jerusalem" },
        { value: "Asia/Kabul", name: "Asia - Kabul" },
        { value: "Asia/Kamchatka", name: "Asia - Kamchatka" },
        { value: "Asia/Karachi", name: "Asia - Karachi" },
        { value: "Asia/Kathmandu", name: "Asia - Kathmandu" },
        { value: "Asia/Khandyga", name: "Asia - Khandyga" },
        { value: "Asia/Kolkata", name: "Asia - Kolkata" },
        { value: "Asia/Krasnoyarsk", name: "Asia - Krasnoyarsk" },
        { value: "Asia/Kuala_Lumpur", name: "Asia - Kuala Lumpur" },
        { value: "Asia/Kuching", name: "Asia - Kuching" },
        { value: "Asia/Kuwait", name: "Asia - Kuwait" },
        { value: "Asia/Macau", name: "Asia - Macau" },
        { value: "Asia/Magadan", name: "Asia - Magadan" },
        { value: "Asia/Makassar", name: "Asia - Makassar" },
        { value: "Asia/Manila", name: "Asia - Manila" },
        { value: "Asia/Muscat", name: "Asia - Muscat" },
        { value: "Asia/Nicosia", name: "Asia - Nicosia" },
        { value: "Asia/Novokuznetsk", name: "Asia - Novokuznetsk" },
        { value: "Asia/Novosibirsk", name: "Asia - Novosibirsk" },
        { value: "Asia/Omsk", name: "Asia - Omsk" },
        { value: "Asia/Oral", name: "Asia - Oral" },
        { value: "Asia/Phnom_Penh", name: "Asia - Phnom Penh" },
        { value: "Asia/Pontianak", name: "Asia - Pontianak" },
        { value: "Asia/Pyongyang", name: "Asia - Pyongyang" },
        { value: "Asia/Qatar", name: "Asia - Qatar" },
        { value: "Asia/Qyzylorda", name: "Asia - Qyzylorda" },
        { value: "Asia/Riyadh", name: "Asia - Riyadh" },
        { value: "Asia/Sakhalin", name: "Asia - Sakhalin" },
        { value: "Asia/Samarkand", name: "Asia - Samarkand" },
        { value: "Asia/Seoul", name: "Asia - Seoul" },
        { value: "Asia/Shanghai", name: "Asia - Shanghai" },
        { value: "Asia/Singapore", name: "Asia - Singapore" },
        { value: "Asia/Srednekolymsk", name: "Asia - Srednekolymsk" },
        { value: "Asia/Taipei", name: "Asia - Taipei" },
        { value: "Asia/Tashkent", name: "Asia - Tashkent" },
        { value: "Asia/Tbilisi", name: "Asia - Tbilisi" },
        { value: "Asia/Tehran", name: "Asia - Tehran" },
        { value: "Asia/Thimphu", name: "Asia - Thimphu" },
        { value: "Asia/Tokyo", name: "Asia - Tokyo" },
        { value: "Asia/Tomsk", name: "Asia - Tomsk" },
        { value: "Asia/Ulaanbaatar", name: "Asia - Ulaanbaatar" },
        { value: "Asia/Urumqi", name: "Asia - Urumqi" },
        { value: "Asia/Ust-Nera", name: "Asia - Ust-Nera" },
        { value: "Asia/Vientiane", name: "Asia - Vientiane" },
        { value: "Asia/Vladivostok", name: "Asia - Vladivostok" },
        { value: "Asia/Yakutsk", name: "Asia - Yakutsk" },
        { value: "Asia/Yangon", name: "Asia - Yangon" },
        { value: "Asia/Yekaterinburg", name: "Asia - Yekaterinburg" },
        { value: "Asia/Yerevan", name: "Asia - Yerevan" },
        { value: "Atlantic/Azores", name: "Atlantic - Azores" },
        { value: "Atlantic/Bermuda", name: "Atlantic - Bermuda" },
        { value: "Atlantic/Canary", name: "Atlantic - Canary" },
        { value: "Atlantic/Cape_Verde", name: "Atlantic - Cape Verde" },
        { value: "Atlantic/Faroe", name: "Atlantic - Faroe" },
        { value: "Atlantic/Madeira", name: "Atlantic - Madeira" },
        { value: "Atlantic/Reykjavik", name: "Atlantic - Reykjavik" },
        { value: "Atlantic/South_Georgia", name: "Atlantic - South Georgia" },
        { value: "Atlantic/St_Helena", name: "Atlantic - St Helena" },
        { value: "Atlantic/Stanley", name: "Atlantic - Stanley" },
        { value: "Australia/Adelaide", name: "Australia - Adelaide" },
        { value: "Australia/Brisbane", name: "Australia - Brisbane" },
        { value: "Australia/Broken_Hill", name: "Australia - Broken Hill" },
        { value: "Australia/Currie", name: "Australia - Currie" },
        { value: "Australia/Darwin", name: "Australia - Darwin" },
        { value: "Australia/Eucla", name: "Australia - Eucla" },
        { value: "Australia/Hobart", name: "Australia - Hobart" },
        { value: "Australia/Lindeman", name: "Australia - Lindeman" },
        { value: "Australia/Lord_Howe", name: "Australia - Lord Howe" },
        { value: "Australia/Melbourne", name: "Australia - Melbourne" },
        { value: "Australia/Perth", name: "Australia - Perth" },
        { value: "Australia/Sydney", name: "Australia - Sydney" },
        { value: "Etc/GMT", name: "Etc - GMT" },
        { value: "Etc/GMT+0", name: "Etc - GMT+0" },
        { value: "Etc/GMT+1", name: "Etc - GMT+1" },
        { value: "Etc/GMT+10", name: "Etc - GMT+10" },
        { value: "Etc/GMT+11", name: "Etc - GMT+11" },
        { value: "Etc/GMT+12", name: "Etc - GMT+12" },
        { value: "Etc/GMT+2", name: "Etc - GMT+2" },
        { value: "Etc/GMT+3", name: "Etc - GMT+3" },
        { value: "Etc/GMT+4", name: "Etc - GMT+4" },
        { value: "Etc/GMT+5", name: "Etc - GMT+5" },
        { value: "Etc/GMT+6", name: "Etc - GMT+6" },
        { value: "Etc/GMT+7", name: "Etc - GMT+7" },
        { value: "Etc/GMT+8", name: "Etc - GMT+8" },
        { value: "Etc/GMT+9", name: "Etc - GMT+9" },
        { value: "Etc/GMT-0", name: "Etc - GMT-0" },
        { value: "Etc/GMT-1", name: "Etc - GMT-1" },
        { value: "Etc/GMT-10", name: "Etc - GMT-10" },
        { value: "Etc/GMT-11", name: "Etc - GMT-11" },
        { value: "Etc/GMT-12", name: "Etc - GMT-12" },
        { value: "Etc/GMT-13", name: "Etc - GMT-13" },
        { value: "Etc/GMT-14", name: "Etc - GMT-14" },
        { value: "Etc/GMT-2", name: "Etc - GMT-2" },
        { value: "Etc/GMT-3", name: "Etc - GMT-3" },
        { value: "Etc/GMT-4", name: "Etc - GMT-4" },
        { value: "Etc/GMT-5", name: "Etc - GMT-5" },
        { value: "Etc/GMT-6", name: "Etc - GMT-6" },
        { value: "Etc/GMT-7", name: "Etc - GMT-7" },
        { value: "Etc/GMT-8", name: "Etc - GMT-8" },
        { value: "Etc/GMT-9", name: "Etc - GMT-9" },
        { value: "Etc/GMT0", name: "Etc - GMT0" },
        { value: "Etc/Greenwich", name: "Etc - Greenwich" },
        { value: "Etc/UCT", name: "Etc - UCT" },
        { value: "Etc/UTC", name: "Etc - UTC" },
        { value: "Etc/Universal", name: "Etc - Universal" },
        { value: "Etc/Zulu", name: "Etc - Zulu" },
        { value: "Europe/Amsterdam", name: "Europe - Amsterdam" },
        { value: "Europe/Andorra", name: "Europe - Andorra" },
        { value: "Europe/Astrakhan", name: "Europe - Astrakhan" },
        { value: "Europe/Athens", name: "Europe - Athens" },
        { value: "Europe/Belgrade", name: "Europe - Belgrade" },
        { value: "Europe/Berlin", name: "Europe - Berlin" },
        { value: "Europe/Bratislava", name: "Europe - Bratislava" },
        { value: "Europe/Brussels", name: "Europe - Brussels" },
        { value: "Europe/Bucharest", name: "Europe - Bucharest" },
        { value: "Europe/Budapest", name: "Europe - Budapest" },
        { value: "Europe/Busingen", name: "Europe - Busingen" },
        { value: "Europe/Chisinau", name: "Europe - Chisinau" },
        { value: "Europe/Copenhagen", name: "Europe - Copenhagen" },
        { value: "Europe/Dublin", name: "Europe - Dublin" },
        { value: "Europe/Gibraltar", name: "Europe - Gibraltar" },
        { value: "Europe/Guernsey", name: "Europe - Guernsey" },
        { value: "Europe/Helsinki", name: "Europe - Helsinki" },
        { value: "Europe/Isle_of_Man", name: "Europe - Isle of Man" },
        { value: "Europe/Istanbul", name: "Europe - Istanbul" },
        { value: "Europe/Jersey", name: "Europe - Jersey" },
        { value: "Europe/Kaliningrad", name: "Europe - Kaliningrad" },
        { value: "Europe/Kiev", name: "Europe - Kiev" },
        { value: "Europe/Kirov", name: "Europe - Kirov" },
        { value: "Europe/Lisbon", name: "Europe - Lisbon" },
        { value: "Europe/Ljubljana", name: "Europe - Ljubljana" },
        { value: "Europe/London", name: "Europe - London" },
        { value: "Europe/Luxembourg", name: "Europe - Luxembourg" },
        { value: "Europe/Madrid", name: "Europe - Madrid" },
        { value: "Europe/Malta", name: "Europe - Malta" },
        { value: "Europe/Mariehamn", name: "Europe - Mariehamn" },
        { value: "Europe/Minsk", name: "Europe - Minsk" },
        { value: "Europe/Monaco", name: "Europe - Monaco" },
        { value: "Europe/Moscow", name: "Europe - Moscow" },
        { value: "Europe/Oslo", name: "Europe - Oslo" },
        { value: "Europe/Paris", name: "Europe - Paris" },
        { value: "Europe/Podgorica", name: "Europe - Podgorica" },
        { value: "Europe/Prague", name: "Europe - Prague" },
        { value: "Europe/Riga", name: "Europe - Riga" },
        { value: "Europe/Rome", name: "Europe - Rome" },
        { value: "Europe/Samara", name: "Europe - Samara" },
        { value: "Europe/San_Marino", name: "Europe - San Marino" },
        { value: "Europe/Sarajevo", name: "Europe - Sarajevo" },
        { value: "Europe/Saratov", name: "Europe - Saratov" },
        { value: "Europe/Simferopol", name: "Europe - Simferopol" },
        { value: "Europe/Skopje", name: "Europe - Skopje" },
        { value: "Europe/Sofia", name: "Europe - Sofia" },
        { value: "Europe/Stockholm", name: "Europe - Stockholm" },
        { value: "Europe/Tallinn", name: "Europe - Tallinn" },
        { value: "Europe/Tirane", name: "Europe - Tirane" },
        { value: "Europe/Ulyanovsk", name: "Europe - Ulyanovsk" },
        { value: "Europe/Uzhgorod", name: "Europe - Uzhgorod" },
        { value: "Europe/Vaduz", name: "Europe - Vaduz" },
        { value: "Europe/Vatican", name: "Europe - Vatican" },
        { value: "Europe/Vienna", name: "Europe - Vienna" },
        { value: "Europe/Vilnius", name: "Europe - Vilnius" },
        { value: "Europe/Volgograd", name: "Europe - Volgograd" },
        { value: "Europe/Warsaw", name: "Europe - Warsaw" },
        { value: "Europe/Zagreb", name: "Europe - Zagreb" },
        { value: "Europe/Zaporozhye", name: "Europe - Zaporozhye" },
        { value: "Europe/Zurich", name: "Europe - Zurich" },
        { value: "Indian/Antananarivo", name: "Indian - Antananarivo" },
        { value: "Indian/Chagos", name: "Indian - Chagos" },
        { value: "Indian/Christmas", name: "Indian - Christmas" },
        { value: "Indian/Cocos", name: "Indian - Cocos" },
        { value: "Indian/Comoro", name: "Indian - Comoro" },
        { value: "Indian/Kerguelen", name: "Indian - Kerguelen" },
        { value: "Indian/Mahe", name: "Indian - Mahe" },
        { value: "Indian/Maldives", name: "Indian - Maldives" },
        { value: "Indian/Mauritius", name: "Indian - Mauritius" },
        { value: "Indian/Mayotte", name: "Indian - Mayotte" },
        { value: "Indian/Reunion", name: "Indian - Reunion" },
        { value: "Pacific/Apia", name: "Pacific - Apia" },
        { value: "Pacific/Auckland", name: "Pacific - Auckland" },
        { value: "Pacific/Bougainville", name: "Pacific - Bougainville" },
        { value: "Pacific/Chatham", name: "Pacific - Chatham" },
        { value: "Pacific/Chuuk", name: "Pacific - Chuuk" },
        { value: "Pacific/Easter", name: "Pacific - Easter" },
        { value: "Pacific/Efate", name: "Pacific - Efate" },
        { value: "Pacific/Enderbury", name: "Pacific - Enderbury" },
        { value: "Pacific/Fakaofo", name: "Pacific - Fakaofo" },
        { value: "Pacific/Fiji", name: "Pacific - Fiji" },
        { value: "Pacific/Funafuti", name: "Pacific - Funafuti" },
        { value: "Pacific/Galapagos", name: "Pacific - Galapagos" },
        { value: "Pacific/Gambier", name: "Pacific - Gambier" },
        { value: "Pacific/Guadalcanal", name: "Pacific - Guadalcanal" },
        { value: "Pacific/Guam", name: "Pacific - Guam" },
        { value: "Pacific/Honolulu", name: "Pacific - Honolulu" },
        { value: "Pacific/Kiritimati", name: "Pacific - Kiritimati" },
        { value: "Pacific/Kosrae", name: "Pacific - Kosrae" },
        { value: "Pacific/Kwajalein", name: "Pacific - Kwajalein" },
        { value: "Pacific/Majuro", name: "Pacific - Majuro" },
        { value: "Pacific/Marquesas", name: "Pacific - Marquesas" },
        { value: "Pacific/Midway", name: "Pacific - Midway" },
        { value: "Pacific/Nauru", name: "Pacific - Nauru" },
        { value: "Pacific/Niue", name: "Pacific - Niue" },
        { value: "Pacific/Norfolk", name: "Pacific - Norfolk" },
        { value: "Pacific/Noumea", name: "Pacific - Noumea" },
        { value: "Pacific/Pago_Pago", name: "Pacific - Pago Pago" },
        { value: "Pacific/Palau", name: "Pacific - Palau" },
        { value: "Pacific/Pitcairn", name: "Pacific - Pitcairn" },
        { value: "Pacific/Pohnpei", name: "Pacific - Pohnpei" },
        { value: "Pacific/Port_Moresby", name: "Pacific - Port Moresby" },
        { value: "Pacific/Rarotonga", name: "Pacific - Rarotonga" },
        { value: "Pacific/Saipan", name: "Pacific - Saipan" },
        { value: "Pacific/Tahiti", name: "Pacific - Tahiti" },
        { value: "Pacific/Tarawa", name: "Pacific - Tarawa" },
        { value: "Pacific/Tongatapu", name: "Pacific - Tongatapu" },
        { value: "Pacific/Wake", name: "Pacific - Wake" },
        { value: "Pacific/Wallis", name: "Pacific - Wallis" }
      ];

      
      // Updated solid color list
      const solidColors = [{
        value: "red",
        name: "Red"
      }, {
        value: "green",
        name: "Green"
      }, {
        value: "blue",
        name: "Blue"
      }, {
        value: "white",
        name: "White"
      }, {
        value: "black",
        name: "Black"
      }, {
        value: "yellow",
        name: "Yellow"
      }, {
        value: "cyan",
        name: "Cyan"
      }, {
        value: "magenta",
        name: "Magenta"
      }, {
        value: "orange",
        name: "Orange"
      }, {
        value: "purple",
        name: "Purple"
      }, {
        value: "pink",
        name: "Pink"
      }, {
        value: "teal",
        name: "Teal"
      }, {
        value: "lime",
        name: "Lime"
      }, {
        value: "amber",
        name: "Amber"
      }, {
        value: "gold",
        name: "Gold"
      }, {
        value: "coral",
        name: "Coral"
      }, {
        value: "lavender",
        name: "Lavender"
      }, {
        value: "skyblue",
        name: "Sky Blue"
      }, {
        value: "forestgreen",
        name: "Forest Green"
      }, {
        value: "maroon",
        name: "Maroon"
      }, {
        value: "olive",
        name: "Olive"
      }, {
        value: "navy",
        name: "Navy"
      }, {
        value: "indigo",
        name: "Indigo"
      }];
      
      // Populate timezone options
      function populateTimezones() {
        const timezoneOptions = document.getElementById('timezoneOptions');
        if (!timezoneOptions) return;
        
        // Clear existing options
        timezoneOptions.innerHTML = '';
        
        // Add search functionality
        const searchBox = document.createElement('input');
        searchBox.type = 'text';
        searchBox.className = 'timezone-search';
        searchBox.placeholder = 'Search timezones...';
        timezoneOptions.appendChild(searchBox);
        
        // Add all timezone options
        timezones.forEach(tz => {
          const div = document.createElement('div');
          div.textContent = tz.name;
          div.setAttribute('data-value', tz.value);
          // Mark selected option (India is default)
          if (tz.value === 'Asia/Kolkata') {
            div.classList.add('selected');
          }
          timezoneOptions.appendChild(div);
        });
        
        // Add search functionality
        searchBox.addEventListener('input', function() {
          const searchTerm = this.value.toLowerCase();
          const options = timezoneOptions.querySelectorAll('div[data-value]');
          options.forEach(option => {
            const text = option.textContent.toLowerCase();
            if (text.includes(searchTerm)) {
              option.style.display = 'block';
            } else {
              option.style.display = 'none';
            }
          });
        });
      }
      
      // Populate solid color options
      function populateSolidColors() {
        const solidColorOptions = document.getElementById('solidColorOptions');
        if (!solidColorOptions) return;
        
        // Clear existing options
        solidColorOptions.innerHTML = '';
        
        // Add all solid color options
        solidColors.forEach(color => {
          const div = document.createElement('div');
          div.textContent = color.name;
          div.setAttribute('data-value', color.value);
          // Mark selected option (Red is default)
          if (color.value === 'red') {
            div.classList.add('selected');
          }
          solidColorOptions.appendChild(div);
        });
      }
      
      // Populate hour and minute options
      function populateTimeOptions() {
        // Hours for alarms (1-12)
        for (let i = 1; i <= 12; i++) {
          const hour = i.toString().padStart(2, '0');
          document.querySelectorAll('.alarm-hour-options').forEach(container => {
            const div = document.createElement('div');
            div.textContent = hour;
            div.setAttribute('data-value', hour);
            // Mark selected hour
            const selected = container.previousElementSibling;
            if (selected && selected.getAttribute('data-value') === hour) {
              div.classList.add('selected');
            }
            container.appendChild(div);
          });
        }
        
        // Minutes for alarms (00, 01, 02, ... 59) - each minute
        for (let i = 0; i < 60; i++) {
          const minute = i.toString().padStart(2, '0');
          document.querySelectorAll('.alarm-minute-options').forEach(container => {
            const div = document.createElement('div');
            div.textContent = minute;
            div.setAttribute('data-value', minute);
            // Mark selected minute
            const selected = container.previousElementSibling;
            if (selected && selected.getAttribute('data-value') === minute) {
              div.classList.add('selected');
            }
            container.appendChild(div);
          });
        }
        
        // Hours for theft detection (1-12)
        const theftStartHourOptions = document.getElementById('theftStartHourOptions');
        const theftEndHourOptions = document.getElementById('theftEndHourOptions');
        if (theftStartHourOptions && theftEndHourOptions) {
          for (let i = 1; i <= 12; i++) {
            const hour = i.toString().padStart(2, '0');
            const startDiv = document.createElement('div');
            startDiv.textContent = hour;
            startDiv.dataset.value = hour;
            // Mark selected start hour
            const startSelected = document.getElementById('theftStartHour');
            if (startSelected && startSelected.getAttribute('data-value') === hour) {
              startDiv.classList.add('selected');
            }
            theftStartHourOptions.appendChild(startDiv);
            
            const endDiv = document.createElement('div');
            endDiv.textContent = hour;
            endDiv.dataset.value = hour;

            // Mark selected end hour
            const endSelected = document.getElementById('theftEndHour');
            if (endSelected && endSelected.getAttribute('data-value') === hour) {
              endDiv.classList.add('selected');
            }
            theftEndHourOptions.appendChild(endDiv);
          }
        }
        
        // Minutes for theft detection (00, 01, 02, ... 59) - each minute
        const theftStartMinuteOptions = document.getElementById('theftStartMinuteOptions');
        const theftEndMinuteOptions = document.getElementById('theftEndMinuteOptions');
        if (theftStartMinuteOptions && theftEndMinuteOptions) {
          for (let i = 0; i < 60; i++) {
            const minuteStr = i.toString().padStart(2, '0');
            const startDiv = document.createElement('div');
            startDiv.textContent = minuteStr;
            startDiv.dataset.value = minuteStr;

            // Mark selected start minute
            const startSelected = document.getElementById('theftStartMinute');
            if (startSelected && startSelected.getAttribute('data-value') === minuteStr) {
              startDiv.classList.add('selected');
            }
            theftStartMinuteOptions.appendChild(startDiv);
            
            const endDiv = document.createElement('div');
            endDiv.textContent = minuteStr;
            endDiv.dataset.value = minuteStr;

            // Mark selected end minute
            const endSelected = document.getElementById('theftEndMinute');
            if (endSelected && endSelected.getAttribute('data-value') === minuteStr) {
              endDiv.classList.add('selected');
            }
            theftEndMinuteOptions.appendChild(endDiv);
          }
        }
        
        // Populate rotate time options (3 to 30 seconds, each second)
        const rotateTimeOptions = document.getElementById('rotateTimeOptions');
        if (rotateTimeOptions) {
          for (let i = 3; i <= 30; i++) {
            const div = document.createElement('div');
            div.textContent = i + ' seconds';
            div.setAttribute('data-value', i.toString());
            // Mark selected option (5 seconds is default)
            if (i === 5) {
              div.classList.add('selected');
            }
            rotateTimeOptions.appendChild(div);
          }
        }
        
        // Populate display ON time options (1 to 5 minutes, each minute)
        const displayOnTimeOptions = document.getElementById('displayOnTimeOptions');
        if (displayOnTimeOptions) {
          for (let i = 1; i <= 5; i++) {
            const div = document.createElement('div');
            div.textContent = i + ' minute' + (i > 1 ? 's' : '');
            div.setAttribute('data-value', i.toString());
            // Mark selected option (1 minute is default)
            if (i === 1) {
              div.classList.add('selected');
            }
            displayOnTimeOptions.appendChild(div);
          }
        }
        
        // Populate theft sound timeout options (5 to 60 seconds, each second)
        const theftSoundOptions = document.getElementById('theftSoundOptions');
        if (theftSoundOptions) {
          for (let i = 5; i <= 60; i++) {
            const div = document.createElement('div');
            div.textContent = i + ' seconds';
            div.setAttribute('data-value', i.toString());
            // Mark selected option (10 seconds is default)
            if (i === 10) {
              div.classList.add('selected');
            }
            theftSoundOptions.appendChild(div);
          }
        }
      }
      
      // Alarm audio button functionality
      function setupAlarmButtons() {
        document.querySelectorAll('.alarm-audio-btn').forEach(button => {
          button.addEventListener('click', function() {
            const alarmNum = this.getAttribute('data-alarm');
            showStatusMessage(`Playing alarm ${alarmNum} audio preview`, 'success');
          });
        });
      }
      
      // Save buttons for each page
      function setupSaveButtons() {
        // Get button elements
        saveClock = document.getElementById('saveClock');
        saveColors = document.getElementById('saveColors');
        saveAlarms = document.getElementById('saveAlarms');
        updateColors = document.getElementById('updateColors');
        
        if (saveColors) {
          saveColors.addEventListener('click', () => {
            showStatusMessage('Color settings saved successfully!', 'success');
            setTimeout(() => {
              showPage('menuPage');
            }, 1000);
          });
        }
        
        if (saveAlarms) {
          saveAlarms.addEventListener('click', () => {
            showStatusMessage('Alarm settings saved successfully!', 'success');
            setTimeout(() => {
              showPage('menuPage');
            }, 1000);
          });
        }
        
        // MODIFICATION 2: Save & Exit buttons in headers
        const saveExitButtons = ['saveExitClockTop', 'saveExitColorsTop', 'saveExitAlarmTop', 'saveExitWifiTop', 'saveExitOTATop'];
        saveExitButtons.forEach(buttonId => {
          const button = document.getElementById(buttonId);
          if (button) {
            button.addEventListener('click', saveAndExit);
          }
        });
        
        if (updateColors) {
          updateColors.addEventListener('click', () => {
            showStatusMessage('Color preview updated!', 'success');
          });
        }
      }
      
      // Initialize the page
      document.addEventListener('DOMContentLoaded', function() {
        // Setup all functionality
        setupNavigation();
        setupDropdowns();
        setupToggleListeners();
        setupAlarmButtons();
        setupSaveButtons();
        
        // Populate timezone options
        populateTimezones();
        // Populate solid color options
        populateSolidColors();
        // Populate time options
        populateTimeOptions();
        // Initialize conditional fields
        handleConditionalFields();
        // Set initial brightness value
        if (brightnessValue && brightnessSlider) {
          brightnessValue.textContent = brightnessSlider.value;
        }
      });
    </script>

    <script>
      /* ================= ESP32 BRIDGE ================= */

      async function loadOtaInfo() {
        const res = await fetch('/api/ota/info');
        const data = await res.json();
        document.getElementById('fwVersion').textContent = data.version;
      }

      function setupOta() {
        const btn = document.getElementById('startOtaBtn');
        const fileInput = document.getElementById('otaFile');
        const progress = document.getElementById('otaProgress');
        const status = document.getElementById('otaStatus');
        const homeBtn = document.getElementById('otaHomeBtn');

        btn.addEventListener('click', () => {
          const file = fileInput.files[0];
          if (!file) {
            status.textContent = 'Select a .bin file';
            return;
          }

          const xhr = new XMLHttpRequest();
          const formData = new FormData();
          formData.append('update', file);

          xhr.upload.onprogress = (e) => {
            if (e.lengthComputable) {
              const percent = Math.round((e.loaded / e.total) * 100);
              progress.style.width = percent + '%';
              status.textContent = `Uploading... ${percent}%`;
            }
          };

          xhr.onload = () => {
            if (xhr.status === 200) {
              status.textContent = 'Update complete!';
              homeBtn.style.display = 'block';
            } else {
              status.textContent = 'OTA failed';
            }
          };

          xhr.open('POST', '/api/ota/update', true);
          xhr.send(formData);
        });

        homeBtn.addEventListener('click', () => {
          location.reload();
        });
      }

      async function saveWifiToESP() {
        const ssid = document.getElementById('wifiSSID').value.trim();
        const password = document.getElementById('wifiPassword').value;

        if (!ssid) {
          showStatusMessage('SSID cannot be empty', 'error');
          return;
        }

        try {
          await fetch('/api/wifi/save', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify({ ssid, password })
          });

          showStatusMessage('WiFi saved. Reconnecting...', 'success');
        } catch (e) {
          showStatusMessage('Failed to save WiFi', 'error');
        }
      }


      function setupWifiPasswordToggle() {
        const input = document.getElementById('wifiPassword');
        const eye = document.getElementById('toggleWifiPassword');
        if (!input || !eye) return;

        eye.addEventListener('click', () => {
          const hidden = input.type === 'password';
          input.type = hidden ? 'text' : 'password';
          eye.className = hidden ? 'fas fa-eye-slash' : 'fas fa-eye';
        });
      }

      async function loadWifiStatus() {
        try {
          const res = await fetch('/api/wifi/status');
          if (!res.ok) throw new Error();

          const wifi = await res.json();

          // ---- ALWAYS populate inputs ----
          const ssidInput = document.getElementById('wifiSSID');
          const passInput = document.getElementById('wifiPassword');
          const statusEl  = document.getElementById('wifiStatus');

          if (ssidInput) ssidInput.value = wifi.ssid || '';
          if (passInput) passInput.value = wifi.password || '';

          // ---- Status text (connected / AP) ----
          if (wifi.connected) {
            statusEl.innerHTML = `
              <span style="color:var(--success-color);font-weight:600;">
                Connected
              </span><br>
              IP: ${wifi.ip}<br>
              RSSI: ${wifi.rssi} dBm
            `;
          } else {
            statusEl.innerHTML = `
              <span style="color:var(--warning-color);font-weight:600;">
                AP Mode / Not Connected
              </span>
            `;
          }

        } catch (e) {
          console.error(e);
        }
      }

      function to24Hour(h, ap) {
        h = Number(h);
        if (ap === 'AM') return h === 12 ? 0 : h;
        return h === 12 ? 12 : h + 12;
      }

      function from24Hour(h) {
        if (h === 0) return { h: '12', ap: 'AM' };
        if (h === 12) return { h: '12', ap: 'PM' };
        if (h > 12) return { h: String(h - 12).padStart(2,'0'), ap: 'PM' };
        return { h: String(h).padStart(2,'0'), ap: 'AM' };
      }

      /* ---------- LOAD ALL FROM ESP ---------- */
      async function loadFromESP() {
        try {
          const res = await fetch('/api/get');
          if (!res.ok) throw new Error('Failed to fetch settings');
          const cfg = await res.json();
          
          /* CLOCK SETTINGS */
          // Brightness
          if (brightnessSlider) brightnessSlider.value = cfg.brightness;
          if (brightnessValue) brightnessValue.innerText = cfg.brightness;
          
          // Toggle switches
          const autoBrightnessElem = document.getElementById('autoBrightness');
          const powerSavingElem = document.getElementById('powerSaving');
          const theftDetectionElem = document.getElementById('theftDetection');
          const theftTimingToggleElem = document.getElementById('theftTimingToggle');
          
          if (autoBrightnessElem) autoBrightnessElem.checked = cfg.autoBrightness || false;
          if (powerSavingElem) powerSavingElem.checked = cfg.powerSaving || false;
          if (theftDetectionElem) theftDetectionElem.checked = cfg.theftDetection || false;
          if (theftTimingToggleElem) theftTimingToggleElem.checked = cfg.theftTimingEnabled || false;
          
          // Timezone
          const timezoneSelect = document.getElementById('timezoneSelect');
          if (timezoneSelect && cfg.timezone) {
            timezoneSelect.dataset.value = cfg.timezone;
            const tz = timezones.find(t => t.value === cfg.timezone);
            if (tz) timezoneSelect.innerText = tz.name;
          }
          
          // Time Mode (12/24 hour)
          const timeModeSelect = document.getElementById('timeModeSelect');
          if (timeModeSelect && cfg.timeMode) {
            timeModeSelect.dataset.value = cfg.timeMode;
            timeModeSelect.innerText = cfg.timeMode === '24' ? '24 Hour Mode' : '12 Hour Mode';
          }
          
          // Display Only (All Rotate, Time Only, etc.)
          const displayOnlySelect = document.getElementById('displayOnlySelect');
          if (displayOnlySelect && cfg.displayOnly) {
            displayOnlySelect.dataset.value = cfg.displayOnly;
            const displayTexts = {
              'all': 'All Rotate',
              'time': 'Time Only',
              'temperature': 'Temperature Only',
              'humidity': 'Humidity Only'
            };
            displayOnlySelect.innerText = displayTexts[cfg.displayOnly] || 'All Rotate';
          }
          
          // Rotate Time
          const rotateTimeSelect = document.getElementById('rotateTimeSelect');
          if (rotateTimeSelect && cfg.rotateTime) {
            rotateTimeSelect.dataset.value = cfg.rotateTime;
            rotateTimeSelect.innerText = cfg.rotateTime + ' seconds';
          }
          
          // Display ON Time (for power saving)
          const displayOnTimeSelect = document.getElementById('displayOnTimeSelect');
          if (displayOnTimeSelect && cfg.displayOnTime) {
            displayOnTimeSelect.dataset.value = cfg.displayOnTime;
            const minuteText = cfg.displayOnTime === '1' ? 'minute' : 'minutes';
            displayOnTimeSelect.innerText = cfg.displayOnTime + ' ' + minuteText;
          }
          
          // Theft Sound Timeout
          const theftSoundSelect = document.getElementById('theftSoundSelect');
          if (theftSoundSelect && cfg.theftSoundTimeout) {
            theftSoundSelect.dataset.value = cfg.theftSoundTimeout;
            theftSoundSelect.innerText = cfg.theftSoundTimeout + ' seconds';
          }
          
          // Theft Timing (Start and End)
          if (cfg.theftStartTime) {
            const theftStartHour = document.getElementById('theftStartHour');
            const theftStartMinute = document.getElementById('theftStartMinute');
            const theftStartAmPm = document.getElementById('theftStartAmPm');
            
            if (theftStartHour && theftStartMinute && theftStartAmPm) {
              const startTime = from24Hour(cfg.theftStartTime.hour);
              theftStartHour.dataset.value = startTime.h;
              theftStartHour.innerText = startTime.h;
              theftStartMinute.dataset.value = String(cfg.theftStartTime.minute).padStart(2, '0');
              theftStartMinute.innerText = String(cfg.theftStartTime.minute).padStart(2, '0');
              theftStartAmPm.dataset.value = startTime.ap;
              theftStartAmPm.innerText = startTime.ap;
            }
          }
          
          if (cfg.theftEndTime) {
            const theftEndHour = document.getElementById('theftEndHour');
            const theftEndMinute = document.getElementById('theftEndMinute');
            const theftEndAmPm = document.getElementById('theftEndAmPm');
            
            if (theftEndHour && theftEndMinute && theftEndAmPm) {
              const endTime = from24Hour(cfg.theftEndTime.hour);
              theftEndHour.dataset.value = endTime.h;
              theftEndHour.innerText = endTime.h;
              theftEndMinute.dataset.value = String(cfg.theftEndTime.minute).padStart(2, '0');
              theftEndMinute.innerText = String(cfg.theftEndTime.minute).padStart(2, '0');
              theftEndAmPm.dataset.value = endTime.ap;
              theftEndAmPm.innerText = endTime.ap;
            }
          }
          
          /* COLOR SETTINGS */
          const colorModeSelect = document.getElementById('colorModeSelect');
          const solidColorSelect = document.getElementById('solidColorSelect');
          const effectSelect = document.getElementById('effectSelect');
          
          if (colorModeSelect) {
            colorModeSelect.dataset.value = cfg.colorMode || 'solid';
            colorModeSelect.innerText = cfg.colorMode === 'solid' ? 'Solid' : 'Effect';
          }
          
          if (solidColorSelect && cfg.solidColor) {
            solidColorSelect.dataset.value = cfg.solidColor;
            const color = solidColors.find(c => c.value === cfg.solidColor);
            if (color) solidColorSelect.innerText = color.name;
          }
          
          if (effectSelect && cfg.effect) {
            effectSelect.dataset.value = cfg.effect;
            effectSelect.innerText = cfg.effect.charAt(0).toUpperCase() + cfg.effect.slice(1);
          }
          
          /* THEME */
          if (themeToggle) {
            themeToggle.checked = cfg.lightTheme || false;
            document.body.classList.toggle('light-theme', cfg.lightTheme);
            themeText.textContent = cfg.lightTheme ? 'Switch to Dark' : 'Switch to Light';
          }
          
          /* ALARMS */
          if (cfg.alarms && Array.isArray(cfg.alarms)) {
            cfg.alarms.forEach((a, i) => {
              const item = document.querySelectorAll('.alarm-item')[i];
              if (!item) return;
              
              const toggle = item.querySelector('.alarm-toggle');
              const hourElem = item.querySelector('.alarm-hour');
              const minuteElem = item.querySelector('.alarm-minute');
              const ampmElem = item.querySelector('.alarm-ampm');
              
              if (toggle) toggle.checked = a.enabled || false;
              
              if (a.hour !== undefined && hourElem) {
                const t = from24Hour(a.hour);
                hourElem.dataset.value = t.h;
                hourElem.innerText = t.h;
              }
              
              if (a.minute !== undefined && minuteElem) {
                const m = String(a.minute).padStart(2,'0');
                minuteElem.dataset.value = m;
                minuteElem.innerText = m;
              }
              
              if (a.hour !== undefined && ampmElem) {
                const t = from24Hour(a.hour);
                ampmElem.dataset.value = t.ap;
                ampmElem.innerText = t.ap;
              }
            });
          }
          
          // Update conditional fields visibility
          handleConditionalFields();
        } catch (error) {
          console.error('Failed to load settings:', error);
          showStatusMessage('Failed to load settings from device', 'error');
        }
      }

      /* ---------- SAVE CLOCK ---------- */
      async function saveClockToESP() {
        try {
          // Get all clock settings
          const autoBrightnessElem = document.getElementById('autoBrightness');
          const powerSavingElem = document.getElementById('powerSaving');
          const timezoneSelect = document.getElementById('timezoneSelect');
          const timeModeSelect = document.getElementById('timeModeSelect');
          const displayOnlySelect = document.getElementById('displayOnlySelect');
          const rotateTimeSelect = document.getElementById('rotateTimeSelect');
          const displayOnTimeSelect = document.getElementById('displayOnTimeSelect');
          const theftDetectionElem = document.getElementById('theftDetection');
          const theftSoundSelect = document.getElementById('theftSoundSelect');
          const theftTimingToggleElem = document.getElementById('theftTimingToggle');
          const theftStartHour = document.getElementById('theftStartHour');
          const theftStartMinute = document.getElementById('theftStartMinute');
          const theftStartAmPm = document.getElementById('theftStartAmPm');
          const theftEndHour = document.getElementById('theftEndHour');
          const theftEndMinute = document.getElementById('theftEndMinute');
          const theftEndAmPm = document.getElementById('theftEndAmPm');
          
          // Prepare data object
          const data = {
            brightness: brightnessSlider ? Number(brightnessSlider.value) : 80,
            autoBrightness: autoBrightnessElem ? autoBrightnessElem.checked : false,
            powerSaving: powerSavingElem ? powerSavingElem.checked : false,
            timezone: timezoneSelect ? timezoneSelect.dataset.value : 'Asia/Kolkata',
            timeMode: timeModeSelect ? timeModeSelect.dataset.value : '24',
            displayOnly: displayOnlySelect ? displayOnlySelect.dataset.value : 'all',
            rotateTime: rotateTimeSelect ? parseInt(rotateTimeSelect.dataset.value) : 5,
            displayOnTime: displayOnTimeSelect ? parseInt(displayOnTimeSelect.dataset.value) : 1,
            theftDetection: theftDetectionElem ? theftDetectionElem.checked : false,
            theftSoundTimeout: theftSoundSelect ? parseInt(theftSoundSelect.dataset.value) : 10,
            theftTimingEnabled: theftTimingToggleElem ? theftTimingToggleElem.checked : false,

            theftStartTime: {
              hour: theftStartHour
                ? to24Hour(theftStartHour.dataset.value, theftStartAmPm.textContent.trim())
                : 23,
              minute: theftStartMinute
                ? parseInt(theftStartMinute.dataset.value)
                : 0
            },

            theftEndTime: {
              hour: theftEndHour
                ? to24Hour(theftEndHour.dataset.value, theftEndAmPm.textContent.trim())
                : 6,
              minute: theftEndMinute
                ? parseInt(theftEndMinute.dataset.value)
                : 0
            }
          };

          
          console.log('Saving clock settings:', data);
          
          await fetch('/api/clock/save', {
            method: 'POST',
            headers: {'Content-Type':'application/json'},
            body: JSON.stringify(data)
          });
          
          showStatusMessage('Clock settings saved', 'success');
        } catch (error) {
          console.error('Failed to save clock settings:', error);
          showStatusMessage('Failed to save clock settings', 'error');
        }
      }

      /* ---------- SAVE COLORS ---------- */
      async function saveColorsToESP() {
        try {
          const colorModeSelect = document.getElementById('colorModeSelect');
          const solidColorSelect = document.getElementById('solidColorSelect');
          const effectSelect = document.getElementById('effectSelect');
          
          const data = {
            mode: colorModeSelect ? colorModeSelect.dataset.value : 'solid',
            color: solidColorSelect ? solidColorSelect.dataset.value : 'red',
            effect: effectSelect ? effectSelect.dataset.value : 'rainbow'
          };
          
          await fetch('/api/colors/save', {
            method: 'POST',
            headers: {'Content-Type':'application/json'},
            body: JSON.stringify(data)
          });
          
          showStatusMessage('Color settings saved', 'success');
        } catch (error) {
          console.error('Failed to save color settings:', error);
          showStatusMessage('Failed to save color settings', 'error');
        }
      }

      /* ---------- COLOR PREVIEW ---------- */
      async function previewColors() {
        try {
          const colorModeSelect = document.getElementById('colorModeSelect');
          const solidColorSelect = document.getElementById('solidColorSelect');
          const effectSelect = document.getElementById('effectSelect');
          
          const data = {
            mode: colorModeSelect ? colorModeSelect.dataset.value : 'solid',
            color: solidColorSelect ? solidColorSelect.dataset.value : 'red',
            effect: effectSelect ? effectSelect.dataset.value : 'rainbow'
          };
          
          await fetch('/api/colors/preview', {
            method: 'POST',
            headers: {'Content-Type':'application/json'},
            body: JSON.stringify(data)
          });
          
          showStatusMessage('Color preview updated', 'success');
        } catch (error) {
          console.error('Failed to preview colors:', error);
          showStatusMessage('Failed to preview colors', 'error');
        }
      }

      /* ---------- SAVE ALARMS ---------- */
      async function saveAlarmsToESP() {
        try {
          const data = [];
          document.querySelectorAll('.alarm-item').forEach(item => {
            const hourElem = item.querySelector('.alarm-hour');
            const minuteElem = item.querySelector('.alarm-minute');
            const ampmElem = item.querySelector('.alarm-ampm');
            const toggleElem = item.querySelector('.alarm-toggle');
            
            if (hourElem && minuteElem && ampmElem && toggleElem) {
              data.push({
                enabled: toggleElem.checked,
                hour: to24Hour(hourElem.dataset.value, ampmElem.textContent.trim()),
                minute: Number(minuteElem.dataset.value)
              });
            }
          });
          
          await fetch('/api/alarms/save', {
            method: 'POST',
            headers: {'Content-Type':'application/json'},
            body: JSON.stringify(data)
          });
          
          showStatusMessage('Alarm settings saved', 'success');
        } catch (error) {
          console.error('Failed to save alarms:', error);
          showStatusMessage('Failed to save alarm settings', 'error');
        }
      }

      /* ---------- PLAY ALARM ---------- */
      function setupAlarmPlayButtons() {
        document.querySelectorAll('.alarm-audio-btn').forEach(btn => {
          btn.addEventListener('click', async () => {
            try {
              await fetch('/api/alarm/play', {
                method: 'POST',
                headers: {'Content-Type':'application/json'},
                body: JSON.stringify({ alarm: btn.dataset.alarm })
              });
              showStatusMessage(`Playing alarm ${btn.dataset.alarm}`, 'success');
            } catch (error) {
              console.error('Failed to play alarm:', error);
              showStatusMessage('Failed to play alarm', 'error');
            }
          });
        });
      }

      /* ---------- THEME ---------- */
      function setupThemeToggle() {
        themeToggle.addEventListener('change', async () => {
          try {
            const isLight = themeToggle.checked;
            document.body.classList.toggle('light-theme', isLight);
            themeText.textContent = isLight ? 'Switch to Dark' : 'Switch to Light';
            
            await fetch('/api/theme', {
              method: 'POST',
              headers: {'Content-Type':'application/json'},
              body: JSON.stringify({ light: isLight })
            });
          } catch (error) {
            console.error('Failed to save theme:', error);
          }
        });
      }

      /* ---------- SAVE & EXIT BUTTONS ---------- */
      function setupSaveExitButtons() {
        // Clock Save & Exit
        const saveExitClockTop = document.getElementById('saveExitClockTop');
        if (saveExitClockTop) {
          saveExitClockTop.addEventListener('click', async () => {
            await saveClockToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // Colors Save & Exit
        const saveExitColorsTop = document.getElementById('saveExitColorsTop');
        if (saveExitColorsTop) {
          saveExitColorsTop.addEventListener('click', async () => {
            await saveColorsToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // Alarm Save & Exit
        const saveExitAlarmTop = document.getElementById('saveExitAlarmTop');
        if (saveExitAlarmTop) {
          saveExitAlarmTop.addEventListener('click', async () => {
            await saveAlarmsToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // WiFi Save & Exit (disabled)
        const saveExitWifiTop = document.getElementById('saveExitWifiTop');
        if (saveExitWifiTop) {
          saveExitWifiTop.addEventListener('click', async () => {
            await saveWifiToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }

        // OTA Save & Exit (disabled)
        const saveExitOTATop = document.getElementById('saveExitOTATop');
        if (saveExitOTATop) {
          saveExitOTATop.addEventListener('click', () => {
            showStatusMessage('OTA settings saved (feature disabled)', 'success');
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
      }

      /* ---------- SAVE AND BACK BUTTONS ---------- */
      function setupSaveBackButtons() {
        // Clock Save and Back
        const saveClockBtn = document.getElementById('saveClock');
        if (saveClockBtn) {
          saveClockBtn.addEventListener('click', async () => {
            await saveClockToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        // WiFi Save and Back
        const saveWifiBtn = document.getElementById('saveWifi');
        if (saveWifiBtn) {
          saveWifiBtn.addEventListener('click', async () => {
            await saveWifiToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // Colors Save and Back
        const saveColorsBtn = document.getElementById('saveColors');
        if (saveColorsBtn) {
          saveColorsBtn.addEventListener('click', async () => {
            await saveColorsToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // Alarm Save and Back
        const saveAlarmsBtn = document.getElementById('saveAlarms');
        if (saveAlarmsBtn) {
          saveAlarmsBtn.addEventListener('click', async () => {
            await saveAlarmsToESP();
            setTimeout(() => showPage('menuPage'), 1000);
          });
        }
        
        // Update Colors Preview
        const updateColorsBtn = document.getElementById('updateColors');
        if (updateColorsBtn) {
          updateColorsBtn.addEventListener('click', previewColors);
        }
      }

      /* ---------- INITIALIZE EVERYTHING ---------- */
      document.addEventListener('DOMContentLoaded', function() {
        setupThemeToggle();
        setupAlarmPlayButtons();
        setupSaveExitButtons();
        setupSaveBackButtons();

        // Load settings
        loadFromESP();
        loadWifiStatus();

        //OTA
        setupOta();
        loadOtaInfo();

        // UI helpers
        setupWifiPasswordToggle();
      });

      </script>
    
    <footer class="site-footer"> © DR Electronics 2026. All rights reserved. </footer>
  </body>
</html>
)rawliteral";