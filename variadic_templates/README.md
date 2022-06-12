# Variadic templates

This example contains methods for constructing templates that should be able to take in aby number of arguments of arbitrary types. This can be useful for providing flexible APIs which can accept the same arguments as class contructors and allocate them elsewhere (for example pass the arguments to an old C-style memory allocation interface for CUDA GPUs).
