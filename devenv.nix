{ pkgs, lib, config, inputs, devenv-zsh, ... }:

{
  imports = [ devenv-zsh.plugin ];
  zsh.enable = true;

  languages.python.enable = true;

  packages = with pkgs; [ 
    platformio 
    figlet
    lolcat
  ];

  scripts = {
    "pio:build".exec = "pio run";
    "pio:upload".exec = "pio run --target upload";
    "pio:monitor".exec = "pio device monitor -b 115200 --quiet";
    "pio:run".exec = "pio run --target upload & pio device monitor -b 115200 --quiet";
    "pio:clean".exec = "pio run --target clean";
  };

  enterShell = ''
    echo
    figlet -f slant "ctrlPad" | lolcat -p 1
    echo
  '';
}
