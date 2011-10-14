namespace :test do
  task :vector do
    emit_vector 'int_vector', 'int', 'tests/vector/int_vector'
    src = [ 'tests/vector/int_vector.gen.c', 'tests/vector/vector_test.c' ]
    src.each do |src_file|
      sh "#{$CC} -x c -arch x86_64 -std=gnu99 -fblocks -c #{File.expand_path src_file} -o #{File.expand_path 'tests/vector/'+src_file.pathmap('%n')}.o"
    end
    sh "#{$CC} -arch x86_64 -o #{File.expand_path 'tests/vector/vector'} #{File.expand_path 'tests/vector/int_vector.gen.o'} #{File.expand_path 'tests/vector/vector_test.o'}"
    sh File.expand_path('tests/vector/vector')
  end
end
