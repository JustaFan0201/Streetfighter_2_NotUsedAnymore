# PTSD 說明書 writing by FanFan
## 1.Transform:
## Translation (平移)
- **資料類型**: `glm::vec2 translation = {0, 0};`
- **用途**: 表示物件在 2D 空間中的位置。
- **詳細說明**:
    - 是一個 2D 向量 `{x, y}`，用於將物件從世界座標系的原點移動到指定的位置。
    - 默認值為 `{0, 0}`，代表物件位於原點。

---

## Rotation (旋轉)
- **資料類型**: `float rotation = 0;`
- **用途**: 表示物件的旋轉角度，單位為弧度。
- **詳細說明**:
    - 正值表示**順時針旋轉**。
    - 負值表示**逆時針旋轉**。
    - 默認值為 `0`，表示物件沒有旋轉。

---

## Scale (縮放)
- **資料類型**: `glm::vec2 scale = {1, 1};`
- **用途**: 表示物件的縮放比例。
- **詳細說明**:
    - 是一個 2D 向量 `{scaleX, scaleY}`，分別對應 X 軸和 Y 軸的縮放。
    - 默認值為 `{1, 1}`，表示沒有縮放（物件為原始大小）。

## 2.Time:
### **1. Delta Time (幀間時間差)**
- **函數：**
  ```cpp
  static double GetDeltaTime();
  ```
  回傳兩幀之間的時間差（單位：秒）。

- **用途：**
    - 確保遊戲中物件的運動和動畫在不同硬體性能下保持一致。
    - 用於速度和位置更新，例如：
      ```cpp
      position += speed * Time::GetDeltaTime();
      ```

---

### **2. 獲取經過的時間**
- **函數：**
  ```cpp
  static unsigned long GetElapsedTimeMs();
  ```
  回傳程式運行後的總經過時間（單位：毫秒）。

- **用途：**
    - 計時器功能，例如倒數計時或事件觸發。
      ```cpp
      unsigned long start = Time::GetElapsedTimeMs();
      if (Time::GetElapsedTimeMs() - start > 3000) {
          // 3 秒後執行的邏輯
      }
      ```
    - 測量函數的執行時間，進行性能分析。

---

### **3. 時間更新**
- **函數：**
  ```cpp
  static void Update();
  ```
  在每幀更新中，由 `Core::Context::Update()` 調用此函數，更新當前時間和幀間時間差。

- **用途：**
    - 保持 `Delta Time` 和經過時間數據的即時性。

---
