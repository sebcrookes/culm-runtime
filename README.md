# Culm Runtime

## About

The Culm Runtime is a runtime environment for Culm bytecode. Culm is an Instruction Set Architecture (ISA) designed for use in my operating system, BambooOS. When ready, this code will be integrated as a git submodule into that project.

## Building and Running

To build the project, run "make". This produces two executables - the runtime, "culm-runtime", and the unit test runner, "culm-test".

## Support/Issues

If you have any issues or suggestions for the project, feel free to get in touch via the contact form on my website https://sebcrookes.co.uk, or create an issue.

## Testing

There is a custom unit testing framework located within the test/ directory. This is run automatically with GitHub Actions as Continuous Integration (CI) to ensure all commits to main and pull requests run as expected according to the ISA specification. "test.h" contains macros which can be used within unit tests allowing for custom asserts to print out the name and location of any errors.

## Copyright

Copyright © 2026 Sebastian Crookes. All rights reserved under copyright laws.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
