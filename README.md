# icu-iana-from-windows

A high-performance Node.js native addon providing seamless conversion from Windows time zone IDs to IANA time zone names using ICU’s official mapping.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Installing ICU](#installing-icu)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [License](#license)

---

## Overview

`icu-iana-from-windows` leverages the ICU C++ API (`getIDForWindowsID`) to deliver accurate and reliable time zone conversions. This package is ideal for applications requiring interoperability between Windows environments and systems using the IANA time zone database.

---

## Features

- **Accurate Mapping:** Reliably converts Windows time zone IDs (e.g., `Pacific Standard Time`) to their IANA equivalents (e.g., `America/Los_Angeles`) using ICU’s official mapping.
- **Straightforward API:** Minimal and intuitive interface for easy integration into Node.js projects.
- **Fills a Standards Gap:** Leverages the ICU C++ API to bridge the gap between Windows and IANA time zones, addressing the lack of native support in ECMA-402 for Windows IDs.
- **High Performance:** Native addon implementation ensures fast and efficient conversions.

---

## Requirements

- Node.js v18 or higher
- ICU v74 or higher

---

## Installing ICU

This package requires ICU (International Components for Unicode) development libraries to be installed on your system before building or installing the native addon. You can install ICU using the following methods depending on your platform:

### Linux (Debian/Ubuntu)

```sh
sudo apt-get update
sudo apt-get install libicu-dev
```

### macOS (Homebrew)

```sh
brew install icu4c
```

### Windows (vcpkg)

We recommend using [vcpkg](https://github.com/microsoft/vcpkg) to manage native dependencies on Windows:

```sh
vcpkg install icu
```

Make sure to integrate vcpkg with your development environment as described in the [vcpkg integration documentation](https://learn.microsoft.com/en-us/vcpkg/examples/installing-and-using-packages).

> **Note:** Ensure that the ICU development libraries are discoverable by your compiler and Node.js build tools (`node-gyp`/`cmake-js`). You may need to set environment variables such as `ICU_ROOT` or update your `PATH` accordingly.

---

## Installation

```sh
npm install icu-iana-from-windows
```

---

## Usage

```js
const { convertWindowsToIana } = require("icu-iana-from-windows");

const iana = convertWindowsToIana("Pacific Standard Time");
console.log(iana); // 'America/Los_Angeles'
```

---

## API Reference

### `convertWindowsToIana(windowsTimeZone: string, territory?: string): string`

- **windowsTimeZone**: The Windows time zone identifier to convert.
- **territory** _(optional)_: Regional code to refine the mapping (e.g., `US` for `America/Los_Angeles`, `CA` for `America/Vancouver`).
- **Returns:** The corresponding IANA time zone name.
- **Throws:** An error if the conversion cannot be performed.

---

## License

[MIT](LICENSE)
