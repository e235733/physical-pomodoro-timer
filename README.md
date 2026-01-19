# Physical Pomodoro Timer

これは、Arduino Mega 2560と4桁7セグメントディスプレイを使用した物理ポモドーロタイマーのプロジェクトです。

## Features

- 勉強時間25分、休憩時間5分のポモドーロタイマー。
- 開始/一時停止機能。
- リセット機能。
- 残り時間を4桁7セグメントディスプレイに表示。
- ボタン操作時とタイマー終了時にブザーで通知。

## Hardware Requirements

- Arduino Mega 2560
- 4桁7セグメントディスプレイ (コモンカソード)
- プッシュボタン x 2
- ブザー
- 配線材とブレッドボード

## Software Requirements

- [PlatformIO](https://platformio.org/)
- ライブラリ: [SevSeg](https://github.com/DeanIsMe/SevSeg)

## Setup and Build

1.  このリポジトリをクローンします。
2.  PlatformIO IDE拡張機能を備えたVisual Studio Codeでプロジェクトを開きます。
3.  「ピン配置」セクションの説明に従って、Arduino Megaおよびその他のコンポーネントを接続します。
4.  プロジェクトをビルドし、Arduino Megaにアップロードします。

## Pin Configuration

| コンポーネント | Arduino Megaのピン |
| :--- | :--- |
| 開始/一時停止ボタン | 2 |
| リセットボタン | 3 |
| ブザー | 8 |
| 7セグメント 数字1 | 22 |
| 7セグメント 数字2 | 23 |
| 7セグメント 数字3 | 24 |
| 7セグメント 数字4 | 25 |
| 7セグメント A | 30 |
| 7セグメント B | 31 |
| 7セグメント C | 32 |
| 7セグメント D | 33 |
| 7セグメント E | 34 |
| 7セグメント F | 35 |
| 7セグメント G | 36 |
| 7セグメント DP | 37 |