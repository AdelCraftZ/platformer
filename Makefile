application=program

build:
	mkdir -p build; cd build; cmake ../.; make; cd ../.;

run:
	cd build; ./$(application);

clean:
	rm -rf build/;

application:
	echo Current application name is: $(application)