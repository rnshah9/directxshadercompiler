#include <climits>
#include <stdint.h>
#include <stdio.h>

#include <fuzzer/FuzzedDataProvider.h>
class VersionSupportInfo {
public:
  bool SkipDxilVersion(unsigned major, unsigned minor);
};

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  FuzzedDataProvider provider(data, size);

  unsigned int a = provider.ConsumeIntegral<unsigned int>();
  unsigned int b = provider.ConsumeIntegral<unsigned int>();
  VersionSupportInfo vsi;
  vsi.SkipDxilVersion(a, b);

  return 0;
}