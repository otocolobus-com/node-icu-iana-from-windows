declare module "icu-iana-from-windows" {
  /**
   * Converts a Windows timezone identifier to an IANA timezone identifier.
   *
   * @param windowsTimezone - The Windows timezone identifier (e.g., "Pacific Standard Time").
   * @param territory - Optional territory code (e.g., "US") to refine the conversion.
   * @returns The corresponding IANA timezone identifier (e.g., "America/Los_Angeles").
   */
  export function convertWindowsToIana(
    windowsTimezone: string,
    territory?: string
  ): string;
}
