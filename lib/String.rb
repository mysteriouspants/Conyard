class String
  def cap_first_letter
    return self.slice(0,1).capitalize + self.slice(1..-1)
  end
end