export PATH=$PATH:$HOME/local/bin
export VALGRIND_LIB="$HOME/local/lib/valgrind"
export PATH=$PATH:$HOME/paraview/bin

source $HOME/repos/spack/share/spack/setup-env.sh

alias ls="ls --color=auto"

ems () {
    emacs "$1" &
}

brc () {
    ems ~/.bashrc
    wait %-
    source ~/.bashrc
}
#sbrc () { source ~/.bashrc; }
