/*
 * Copyright 2018 Google, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Gabe Black
 */

#ifndef __SYSTEMC_CORE_SC_MAIN_FIBER_HH__
#define __SYSTEMC_CORE_SC_MAIN_FIBER_HH__

#include "base/fiber.hh"
#include "base/logging.hh"

namespace sc_gem5
{

class ScMainFiber : public Fiber
{
  private:
    int _argc = 0;
    char **_argv = NULL;
    std::string _resultStr;
    int _resultInt = 1;

    bool _called = false;

  public:
    int argc() { return _argc; }
    const char *const *argv() { return _argv; }
    std::string resultStr() { return _resultStr; }
    int resultInt() { return _resultInt; }
    bool called() { return _called; }

    void
    setArgs(int new_argc, char **new_argv)
    {
        _argc = new_argc;
        _argv = new_argv;
    }

    void main() override;
};

extern ScMainFiber scMainFiber;

} // namespace sc_gem5

#endif // __SYSTEMC_CORE_SC_MAIN_FIBER_HH__
