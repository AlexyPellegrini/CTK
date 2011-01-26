/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.commontk.org/LICENSE

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/
/*=========================================================================

   Program: ParaView
   Module:    $RCSfile$

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

#ifndef __ctkPythonConsole_h
#define __ctkPythonConsole_h

// CTK includes
#include <ctkConsole.h>
#include "ctkScriptingPythonWidgetsExport.h"


///
///  Qt widget that provides an interactive "shell" interface to an embedded Python interpreter.
///  You can put an instance of ctkPythonConsole in a dialog or a window, and the user will be able
/// to enter Python commands and see their output, while the UI is still responsive.
///
/// \sa ctkConsole

class ctkPythonConsolePrivate;
class ctkAbstractPythonManager;

class CTK_SCRIPTING_PYTHON_WIDGETS_EXPORT ctkPythonConsole : public ctkConsole
{
  Q_OBJECT
  
public:
  typedef ctkConsole Superclass;
  ctkPythonConsole(ctkAbstractPythonManager* pythonManager, QWidget* parentObject = 0);
  virtual ~ctkPythonConsole();

  /// Prints some text on the shell.
  void printMessage(const QString&);

  /// Given a python variable name, lookup its attributes and return them in a string list.
  QStringList pythonAttributes(const QString& pythonVariableName) const;

signals:
  void executing(bool);

public slots:
  void clear();
  void executeScript(const QString&);

protected slots:
  void printStderr(const QString&);
  void printStdout(const QString&);

  void onExecutePythonCommand(const QString&);

private:
  Q_DECLARE_PRIVATE(ctkPythonConsole);
  Q_DISABLE_COPY(ctkPythonConsole);

  void internalExecuteCommand(const QString&);
};

#endif

