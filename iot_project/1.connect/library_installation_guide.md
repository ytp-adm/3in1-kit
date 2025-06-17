# ESP8266 Blynk プロジェクト用ライブラリインストールガイド

## 必要なライブラリ

### 1. Blynkライブラリ
```
Arduino IDE → ツール → ライブラリを管理
検索: "Blynk"
作者: Volodymyr Shymanskyy
バージョン: 最新版をインストール
```

### 2. ESP8266ライブラリ
```
Arduino IDE → ツール → ライブラリを管理
検索: "WiFiEsp"
作者: bportaluri
バージョン: 最新版をインストール
```

### 3. ボードマネージャーの設定
```
Arduino IDE → ファイル → 環境設定
追加のボードマネージャのURL:
http://arduino.esp8266.com/stable/package_esp8266com_index.json

ツール → ボード → ボードマネージャ
検索: "ESP8266"
"ESP8266 by ESP8266 Community" をインストール
```

## インストール後の確認

1. Arduino IDEを再起動
2. スケッチ → ライブラリをインクルード で以下が表示されることを確認：
   - Blynk
   - WiFiEsp
   - SoftwareSerial (Arduino標準ライブラリ)

## 代替案

もしライブラリのインストールができない場合は、以下の代替コードを使用してください：
- WiFiEspライブラリの代わりにESP8266WiFiライブラリを使用
- または、ESP8266ボード自体を使用してArduino Unoを使わない構成