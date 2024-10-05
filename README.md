# CS106L Assignments 

This repository contains starter code for Stanford CS106L, a course on Standard C++ programming.

## Getting Started

Before getting started, a few prerequisites:

* You will need [Python 3.8](https://www.python.org/downloads/) or higher on your computer. You can check by running `python3 --version` (`python --version` on Windows) in a terminal.
* You will need an IDE you can code in. We encourage you to use VSCode for this class ([see guide below](#vscode-setup-instructions)), but you may use any IDE that you can comfortably write and compile C++ code in.
* You will need [Git](https://git-scm.com/). If you are using VSCode, you should already have this. You can check by running `git --version` in a terminal.

Next, download the starter code. Open up a terminal (if you are using VSCode, hit <kbd>Ctrl+\`</kbd> or go to **Terminal > New Terminal** at the top) and run the following command:

```sh
git clone https://github.com/cs106l/cs106l-assignments.git
```

which will download the starter code into a folder `cs106l-assignments`. If you are using VSCode, you can then open up a VSCode workspace dedicated to CS106L:

```sh
cd cs106l-assignments && code .
```

and you are ready to go!

### Fetching assignments

As we update existing assignments and release new ones, we will push updates to this repository. To fetch a new assignment, open up a terminal to your `cs106l-assignments` directory and run

```sh
git pull origin main
```

You should now have the latest starter code!

## VSCode Setup Instructions

We recommend using VSCode to write C++ code for this class. See instructions below to setup VSCode/GCC for your machine.

### Mac

#### Step One: Installing VSCode

Go to [this link](https://code.visualstudio.com/docs/setup/mac)
and download Visual Studio Code for Mac. Follow the instructions on this webpage under the
section **Installation**.

Inside VSCode, head to the extensions tab <img src="docs/vscode-extensions.png" display="inline" height="20px"></img> and search for **C/C++**. Click on the **C/C++** extension, and then click **Install**.

<b> 🥳 At this point you should successfully have VSCode on your Mac 👏 </b>

#### Step Two: Installing a C++ Compiler

<ol>
  <li>
    Check if you have Homebrew by running 
    <pre lang="sh">brew --version</pre>
    If you get something like
    <pre lang="sh">
brew --version
Homebrew 4.2.21</pre>
    then <b>skip step 2 and go to step 3.</b> If you get anything else that looks sus then proceed to step 2!
  </li>
  <li>
    Run this command:
    <pre lang="sh">/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</pre>
    which is going to download Homebrew🍺 which is a package manager. Woot woot.
  </li>
  <li>
    Run the following command:
    <pre lang="sh">brew install gcc</pre>
    which is going to install the compiler (GCC).
  </li>
  <li>
    After installing GCC, restart your terminal and verify that everything worked by running the following command:
    <pre lang="sh">g++ --version</pre>
  </li>
</ol>

### Windows

#### Step One: Installing VSCode

Go to [this link](https://code.visualstudio.com/docs/setup/windows)
and download Visual Studio Code for Windows. Follow the instructions on this webpage under the
section **Installation**.

Inside VSCode, head to the extensions tab <img src="docs/vscode-extensions.png" display="inline" height="20px"></img> and search for **C/C++**. Click on the **C/C++** extension, and then click **Install**.

<b> 🥳 At this point you should successfully have VSCode on your PC 👏 </b>

#### Step Two: Installing a C++ Compiler

1. Follow the instructions at [this link](https://code.visualstudio.com/docs/cpp/config-mingw)
    * You should be doing the instructions under **Installing the
MinGW-w64 toolchain.**

2. After fully following the instructions under **Installing the
MinGW-w64 toolchain** you should now be able to verify
everything worked by running the following command:

```sh
g++ --version
```