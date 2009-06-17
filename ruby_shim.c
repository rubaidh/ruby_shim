/* Ruby Shim
 *
 * Copyright (c) 2009 Graeme Mathieson and Rubaidh Ltd.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define ENV "LD_LIBRARY_PATH"
#define ENV_VALUE "/opt/local/lib"
#define REAL_RUBY "/opt/ruby-enterprise/bin/ruby.real"

int main(int argc, char **argv) {

  if(setenv(ENV, ENV_VALUE, 1) < 0) {
    printf("Error: Failed to set the environment %s=%s: %s.\n", ENV, ENV_VALUE, strerror(errno));
    exit(EXIT_FAILURE);
  }

  if(execv(REAL_RUBY, argv) < 0) {
    printf("Error: Failed to execv() the real ruby interpreter: %s.\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  /* Never reached! */
  return(0);
}