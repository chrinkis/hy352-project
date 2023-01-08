## For TAs

### Team Members
- Grigoroudis Nikolaos, csd4619@csd.uoc.gr
- Christinakis Alexandros, csd4764@csd.uoc.gr

### IDE
- `NVIM v0.8.1`

### C++ Version
- version 11

### Compilation/Run/Testing Process
- compile: `bash compile.sh`
- compile and run: `bash compile.sh -r`
- compile and test: `bash compile.sh -t`
- view code after preprocessor: `bash compile.sh -p`

### Testing machine
- name: `harpia`

## Development

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
