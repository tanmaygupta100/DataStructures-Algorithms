Algorithm decimalToBinary(n)
{
  // This algorithm converts a positive decimal integer to a binary string.
  // input: n - positive decimal integer
  // ouput: binary representation of n

  // Initializing variable:
  binaryLine = "" // Empty string variable

  if n == 0 then:
    binaryLine = "0"
  
  while n > 0 do:
    // keep doing the division while n is a whole number greater than 0
    // loop stops after n=1/2=0 is achieved.
  {
    r = n mod 2
      // remainder "r" is either 1 or 0.
    binaryLine = r + binaryLine
      // Adds each remainder to the FRONT of binary line.
    n = n / 2
      // Final step in algorithm to keep looping & reducing the number.
      // With each reduction, the new n value is tranlated to 1 or 0,
        // and then added to the binary line.
  }
  return binaryLine
}
