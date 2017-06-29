pkg_name = gnuplot
version = 5.0.6
format = tar.gz
pkg_install_dir = install
bin = bin
util = tar
FLAGS = xf

pkg_dir = $(pkg_name)-$(version)
pkg_file = $(pkg_name)-$(version).$(format)
prefix = $(CURDIR)/$(pkg_install_dir)

$(prefix)/$(bin)/$(pkg_name) : $(pkg_dir)
	mkdir -p $(prefix)
	cd $(pkg_dir) && ./configure --prefix="$(prefix)"
	make -C $(pkg_dir)
	make -C $(pkg_dir) install

$(pkg_dir) : $(pkg_file)
	$(util) $(FLAGS) $(pkg_file)

display :
	@ECHO $(pkg_dir)
	@ECHO $(pkg_file)
	@ECHO $(prefix)

clean : 
	rm -rf $(pkg_dir) $(prefix)
