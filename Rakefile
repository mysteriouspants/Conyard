# Created on 10 October 2011.
# Copyright 2011 Chris Miller. All rights reserved.

require 'rubygems'
require 'erb'

templates_path = 'templates'
test_source_path = 'tests'
test_products_path = 'bin'

vector_header_template = 'vector.h.erb'
vector_implem_template = 'vector.c.erb'

cc = 'clang'
cxx = 'clang++'

CLEAN = FileList['.o']

desc "Creates a new fast, lean C vector implementation; useage is: rake vector[name, type, outfile]"
task :vector, :name, :type, :outfile do |t, args|
  args.with_defaults(:name => 'int_vector', :type => 'int', :outfile => 'int-vector')
  
  @name = args.name
  @type = args.type
  @outfile = File.expand_path args.outfile
  @guard = args.outfile.pathmap("%n").gsub(/\-/,'_').upcase
  
  out_header = ERB.new(File.read(File.join(templates_path, vector_header_template))).result
  File.new(@outfile+".gen.h", "w").write(out_header)
  out_implem = ERB.new(File.read(File.join(templates_path, vector_implem_template))).result
  File.new(@outfile+".gen.c", "w").write(out_implem)
end

file 'tests/int-vector.gen.c' do
  Rake::Task["vector"].invoke 'int_vector', 'int', File.join(test_source_path, 'int-vector')
end

file 'bin/int-vector.gen.o' => 'tests/int-vector.gen.c' do
  sh "#{cc} -x c -arch x86_64 -c tests/int-vector.gen.c -o bin/int-vector.gen.o"
end

file 'bin/vector_test.o' => 'tests/vector_test.c' do 
  sh "#{cc} -x c -arch x86_64 -c tests/vector_test.c -o bin/vector_test.o"
end

file 'bin/vector' => ['bin/vector_test.o', 'bin/int-vector.gen.o'] do
  sh "#{cc} -arch x86_64 -o bin/vector bin/vector_test.o bin/int-vector.gen.o"
end

task :test_vector => ['bin/vector'] do
  sh "bin/vector"
end
