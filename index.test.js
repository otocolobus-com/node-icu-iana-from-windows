const assert = require("node:assert");
const test = require("node:test");

test("should be able to load native binding", async (t) => {
  const binding = require(".");
  assert.ok(binding);
  assert.equal(typeof binding, "object");
  assert.equal(typeof binding.convertWindowsToIana, "function");
});

test("should be able to load native binding and execute it", async (t) => {
  const binding = require(".");
  assert.equal(
    binding.convertWindowsToIana("Pacific Standard Time"),
    "America/Los_Angeles"
  );
});

test("should map Windows timezones to IANA timezones based on region", async (t) => {
  const binding = require(".");
  assert.equal(
    binding.convertWindowsToIana("Pacific Standard Time", "US"),
    "America/Los_Angeles"
  );
  assert.equal(
    binding.convertWindowsToIana("Pacific Standard Time", "CA"),
    "America/Vancouver"
  );
  assert.equal(
    binding.convertWindowsToIana("Eastern Standard Time", "US"),
    "America/New_York"
  );
  assert.equal(
    binding.convertWindowsToIana("Eastern Standard Time", "CA"),
    "America/Toronto"
  );
});

test("should throw an error for empty timezone", async (t) => {
  const binding = require(".");
  assert.throws(
    () => {
      binding.convertWindowsToIana("");
    },
    {
      name: "Error",
      message: "Expected a non-empty Windows timezone ID as the first argument",
    }
  );
});

test("should throw an error for invalid timezone", async (t) => {
  const binding = require(".");
  assert.throws(
    () => {
      binding.convertWindowsToIana("Invalid/Timezone");
    },
    {
      name: "Error",
      message: "Failed to convert Windows timezone ID to IANA",
    }
  );
});
