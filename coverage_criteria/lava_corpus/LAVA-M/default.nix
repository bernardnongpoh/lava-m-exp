let
	nixpkgs = builtins.fetchTarball {
		url = "https://github.com/NixOS/nixpkgs/archive/9f3fe63b5f491db8a2b9daf20d4cdd4f13623542.tar.gz";
		sha256 = "1p5mb8g2ri0i1ycz35jfsc0y8s4n2difyvf7agjmrzpizvp46k9p";
	};
	pkgs = (import nixpkgs {}).pkgsi686Linux;
in
	pkgs.stdenv.mkDerivation {
		name = "whatever";
		buildInputs = with pkgs; [ perl gnulib autoreconfHook ];
	}

