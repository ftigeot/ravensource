#    Description                  : Enable LLVM build with gcc 8

--- include/llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h
+++ include/llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h
@@ -687,8 +687,8 @@ private:
 
   uint32_t getTrampolineSize() const { return RemoteTrampolineSize; }
 
-  Expected<std::vector<char>> readMem(char *Dst, JITTargetAddress Src,
-                                      uint64_t Size) {
+  Expected<std::vector<uint8_t>> readMem(char *Dst, JITTargetAddress Src,
+                                         uint64_t Size) {
     // Check for an 'out-of-band' error, e.g. from an MM destructor.
     if (ExistingError)
       return std::move(ExistingError);
