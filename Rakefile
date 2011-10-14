# Created on 10 October 2011.
# Copyright 2011 Chris Miller. All rights reserved.

require 'rubygems' if RUBY_VERSION < '1.9'
require 'rake'
require 'erb'

$CC = 'clang'
$CXX = 'clang++'

CLEAN = FileList['.o']

Dir.glob('**/*.rake').each { |r| import r }

desc 'Runs a task using a file for arguments'
task :generate, :argfile do
  # Some idea I had of doing stuff from config files
end
