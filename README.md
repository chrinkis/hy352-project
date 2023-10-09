## Repository status

This repository is an unmaintained mirror of the repository
[niex/hy352-project](https://gitlab-csd.datacenter.uoc.gr/niex/hy352-project).

## For TAs

### Team Members
- Grigoroudis Nikolaos, csd4619@csd.uoc.gr
- Christinakis Alexandros, csd4764@csd.uoc.gr

### IDE (not exactly)
Both developers used [Neovim](https://neovim.io/) with
[Clangd](https://clangd.llvm.org/) for language server. For debuging we used
[VSCodium](https://vscodium.com/) with
[CodeLLDB](https://open-vsx.org/extension/vadimcn/vscode-lldb).

### C++ Version
- C++11

### Compilation/Run/Testing Process

#### Using cmake (recommended)
- compile: `bash compile.sh`
- compile and run: `bash compile.sh -r`
- compile and test: `bash compile.sh -t`
- view code after preprocessor: `bash compile.sh -p`

#### Using make
- compile: `bash compile.sh -m`
- compile and run: `bash compile.sh -m && ./demo.out`
- compile and test: not supported
- view code after preprocessor: not supported

> In order to run the unit tests, you need to have cloned the
[Catch2](https://github.com/catchorg/Catch2) library into `lib/Catch2`
(in root directory of the project).

### Things to note
- We tried (and we think we accomplished it) to implement
everything according to the project requirements.
- We didn't have enough time to write unit tests.

### Testing machine
- name: harpia

## For Developers

### Code
1. Use `this` inside a method to access class data or methods
2. Use `const` keyword when a method doesn't modify the state of the object
3. Use only `*_cast<>()` template when casting
4. Use `override` keyword when overriding a virtual method

### Style
1. Format the code according to `.clang-format`

### Git
1. Follow [conventional commits](https://www.conventionalcommits.org/en/v1.0.0/) rules. A more user-friendly guide (although it's unofficial) can be found [here](https://gist.github.com/qoomon/5dfcdf8eec66a051ecd85625518cfd13)
1. Format the code before stage/commit
