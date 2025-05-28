# icu-iana-from-windows

A high-performance Node.js native addon providing seamless conversion from Windows time zone IDs to IANA time zone names using ICU’s official mapping.

## Overview

`icu-iana-from-windows` leverages the ICU C++ API (`getIDForWindowsID`) to deliver accurate and reliable time zone conversions. This package is ideal for applications requiring interoperability between Windows and IANA time zone standards.

## Features

- **Accurate Mapping:** Reliably converts Windows time zone IDs (e.g., `Pacific Standard Time`) to their IANA equivalents (e.g., `America/Los_Angeles`) using ICU’s official mapping.
- **Straightforward API:** Minimal and intuitive interface for easy integration into Node.js projects.
- **Fills a Standards Gap:** Leverages the ICU C++ API to bridge the gap between Windows and IANA time zones, addressing the lack of native support in ECMA-402 for Windows IDs.
- **High Performance:** Native addon implementation ensures fast and efficient conversions.

## Installation

```sh
npm install icu-iana-from-windows
```

## Usage

```js
const { convertWindowsToIana } = require("icu-iana-from-windows");

const iana = convertWindowsToIana("Pacific Standard Time");
console.log(iana); // 'America/Los_Angeles'
```

## API Reference

### `convertWindowsToIana(windowsTimeZone: string, territory?: string): string`

- **windowsTimeZone**: The Windows time zone identifier to convert.
- **territory** _(optional)_: Regional code to refine the mapping (e.g., `US` for `America/Los_Angeles`, `CA` for `America/Vancouver`).
- **Returns:** The corresponding IANA time zone name.
- **Throws:** An error if the conversion cannot be performed.

## Requirements

- Node.js v18 or higher
- ICU v74 or higher

## License

[MIT](LICENSE)
