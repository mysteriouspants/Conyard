# Created on 10 October 2011.
# Copyright 2011 Chris Miller. All rights reserved.

require 'rubygems' if RUBY_VERSION < '1.9'
require 'rake'
require 'erb'

templates_path = 'templates'
test_source_path = 'tests'
test_products_path = 'bin'

$CC = 'clang'
$CXX = 'clang++'

CLEAN = FileList['.o']

Dir.glob('**/*.rake').each { |r| import r }

desc 'Runs a task using a file for arguments'
task :generate, :argfile do
  
end
