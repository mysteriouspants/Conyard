task :test_vector do
  rm 'tests/vector/int_vector.gen.h'
  rm 'tests/vector/int_vector.gen.c'
  Rake::Task["vector"].invoke 'int_vector', 'int', 'tests/vector/int_vector'
  sh "#{$CC} -x c -arch x86_64 -c tests/vector/int_vector.gen.c -o bin/int_vector.gen.o"
  sh "#{$CC} -x c -arch x86_64 -c tests/vector/vector_test.c -o bin/vector_test.o"
  sh "#{$CC} -arch x86_64 -o bin/vector bin/vector_test.o bin/int_vector.gen.o"
  sh "bin/vector"
end