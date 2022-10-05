# Pimpl idiom

`Pimpl` or pointer to implementation idiom is a useful programming technique that allows one to separate the full implementation code from the declared interface. With the use of this technique, when writing changes to the implementation, this does not cause the need to recompile the code that includes the file with the declared interface. You only need to recompile and relink the new changes in the implementation to your program.
