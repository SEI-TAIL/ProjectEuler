@memo = {}                                                                          
def collatz(n)                                                                      
  unless @memo[n]                                                                   
    r = if n == 1                                                                   
          1                                                                         
        elsif n % 2 == 0
          collatz(n/2) + 1                                                          
        else                                                                        
          collatz(3*n + 1) + 1                                                      
        end                                                                         
    @memo[n] = r                                                                    
  end                                                                               
  @memo[n]                                                                          
end                                                                                 
                                                                                    
LIMIT = 100 * 10000                                                                 
max = 0                                                                             
max_i = 0                                                                           
                                                                                    
1.upto(LIMIT) do |i|                                                                
  # p i if i % 100000 == 0                                                            
  r = collatz(i)                                                                    
  if max < r                                                                        
    max = r                                                                         
    max_i = i                                                                       
  end                                                                               
end                                                                                 
                                                                                    
puts "#{max_i} : chain (#{max})" 
