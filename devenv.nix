{ pkgs, lib, config, inputs, devenv-zsh, ... }:

{
  imports = [ devenv-zsh.plugin ];
  zsh.enable = true;

  languages.python.enable = true;

  packages = with pkgs; [ 
    platformio 
  ];
}
