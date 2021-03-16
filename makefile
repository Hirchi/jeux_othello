.ONESHELL:
all : prg tests rapport doc

prg : 
	cd programme && make prg && cd ..

tests : 
	cd programme && make tests && cd ..

rapport : ./rapport/src/rapport.pdf

./rapport/src/rapport.pdf:
	cd ./rapport/src  
	make rapport.pdf 
	cd ../..

doc :
	cd programme && make doc && cd ..

clean :
	cd programme && make clean && cd ..
	cd ./rapport/src && make clean && cd ..
