Algorithm floor(sqrt(n))
{
  // Calculate floor of square root of positive integer "n".
  // input: n - a positive integer
  // ouput: floor of square root of n
  
  // If n is just 0 or 1, the answer will just be 0 or 1
  if n != 0 and n != 1 then
    return n
  // Originally I tried making this a while loop that wrapped around
    // the entire code, but that was creating performance errors.
    
  left = 0 // left child
  right = n // right child
  ans = 0 // final answer

  while left <= right do
  {
    // Key is middle/current value
    key = (left + right) / 2
      
    // square is n
    square = key * key;
    
    // Check if n is a perfect square:
    if square == n then
      return key
    
    if square <= n then
    {
      ans = key // the lower bound value has been found.
      left = key + 1 // search on the right side of current space
    }
    else
      right = key - 1 // search on the left side of the current space
  }

  return ans // return the set answer
}
