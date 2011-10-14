desc "Creates a new fast, lean C vector implementation; useage is: rake vector[name, type, outfile]"
task :vector, :name, :datatype, :outfile do |t, args|
  args.with_defaults(:name => 'int_vector', :datatype => 'int', :outfile => 'int_vector')
  
  @name = args.name
  @type = args.datatype
  @outfile = File.expand_path args.outfile
  @guard = args.outfile.pathmap("%n").gsub(/\-/,'_').upcase
  
  headertmpl = 'structure-kits/vector/vector.h.erb'
  impltmpl = 'structure-kits/vector/vector.c.erb'
  
  File.new(@outfile+".gen.h", "w").write(ERB.new(File.read(headertmpl)).result)
  File.new(@outfile+".gen.c", "w").write(ERB.new(File.read(impltmpl)).result)
end
