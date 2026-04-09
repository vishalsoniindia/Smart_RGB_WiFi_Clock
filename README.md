# 🚀 ESP32 Easy Upload Tool

A simple way to erase and upload code to your ESP32 using a batch file.  

---

## 📌 How It Works
The included **`esp32_upload.bat`** file will:
- Automatically erase the ESP32 flash memory
- Upload your program
- Allow quick reprogramming for multiple devices

---

## 🔧 Steps to Upload Code

1. Open the folder and **double-click** `esp32_upload.bat`.
2. If Windows shows *"Windows Protected your PC"*, click:
   - **More Info**
   - **Run Anyway**
3. From the COM port list, **select the list number [NOT COM NUMBER]** where your ESP32 is connected.
4. Press **Enter** to continue.
5. Wait until you see:  
   ✅ **"Flash Complete"** at the end.
6. Press **any key** if you want to program another device.

---

## ⚠️ Notes
- Make sure your ESP32 is properly connected via USB.
- Run the script with administrator privileges if you face permission issues.

---

✨ That’s it! Your ESP32 should now be running the uploaded code.
