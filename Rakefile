# Created on 10 October 2011.
# Copyright 2011 Chris Miller. All rights reserved.

require 'rubygems'
require 'erb'

templates_path = 'templates'
test_source_path = 'tests'
test_products_path = 'bin'

vector_header_template = 'vector.h.erb'
vector_implem_template = 'vector.c.erb'

$CC = 'clang'
$CXX = 'clang++'

CLEAN = FileList['.o']

Dir.glob('**/*.rake').each { |r| import r }

desc 'Runs a task using a file for arguments'
task :generate, :argfile do
  
end
