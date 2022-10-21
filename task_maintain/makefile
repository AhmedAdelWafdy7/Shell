.phony: clean	
run: shell
	@./shell

shell: headers.c headers.h main.c clean
	@gcc -shared -fpic -o libtask.so headers.c headers.h
	@gcc -o shell main.c ./libtask.so
	@echo "Shell has been created ,ready to run"
clean:
	@rm -f *.o *.h.gch *.so shell	
