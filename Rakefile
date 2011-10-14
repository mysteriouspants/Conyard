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
task :run, :argfile do |t, args|
  argfile=args.argfile
  raise 'Dude, no argument? You jerk!' unless argfile
  config=File.read(File.expand_path(argfile))
  lines = Array.new
  config.each_line { |line| lines << line.strip }
  tn = lines[0]
  lines = lines[1 .. -1]
  Rake::Task[tn].invoke *lines
end
