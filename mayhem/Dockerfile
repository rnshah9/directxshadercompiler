FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y vim less file build-essential cmake ninja-build python-is-python3 git clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -GNinja -DCMAKE_BUILD_TYPE=Release -C ../cmake/caches/PredefinedParams.cmake
RUN ninja

RUN clang++ /repo/mayhem/fuzz_SkipDxilVersion.cpp -fsanitize=fuzzer,address -L /repo/build/lib/ -lHLSLTestLib -lgtest -lLLVMDxcSupport -lLLVMOption -lLLVMSupport -ltinfo -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /repo/build /repo/build
COPY --from=builder /fuzz /fuzz_SkipDxilVersion
