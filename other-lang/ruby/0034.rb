#!/usr/bin/ruby

def solution
  $total = 0
  
  for $i in 3..999999999
    $sum = 0
    $digits = $i.to_s.split(//)

    $digits.each do |d|
      $sum += factorial(d)
    end
    
    if $sum == $i
      $total += $i
      puts "Num :: #{$i}"
      puts "Sum :: #{$total}"
    end
  end
end

def factorial(num)
  fact = 1
  num.to_i.downto(1) { |n| fact *= n }
  return fact
end  

#Main
solution
