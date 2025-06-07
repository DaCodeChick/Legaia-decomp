import sys
import re
import struct

def convert_byte_array_to_uint32(input_str):
    # Extract all hex values from the input string
    byte_values = re.findall(r'0x[0-9a-fA-F]+', input_str)
    
    # Convert hex strings to integers
    bytes = [int(x, 16) for x in byte_values]
    
    # Check if the length is a multiple of 4
    if len(bytes) % 4 != 0:
        raise ValueError("Input byte array length must be a multiple of 4")
    
    # Convert to 32-bit unsigned integers (little endian)
    uint32_values = []
    for i in range(0, len(bytes), 4):
        # Pack 4 bytes into a little-endian unsigned int
        packed = struct.pack('<4B', *bytes[i:i+4])
        uint32 = struct.unpack('<I', packed)[0]
        uint32_values.append(uint32)
    
    return uint32_values

def generate_output_c_array(uint32_values):
    lines = []
    lines.append("{")
    
    # Format with 4 values per line
    for i in range(0, len(uint32_values), 4):
        chunk = uint32_values[i:i+4]
        line = "    " + ", ".join(f"0x{val:08X}" for val in chunk)
        if i + 4 < len(uint32_values):
            line += ","
        lines.append(line)
    
    lines.append("};")
    return "\n".join(lines)

def main():
    if len(sys.argv) != 2:
        print("Usage: python bytes2uints.py \"{ 0x01, 0x02, 0x03, 0x04 }\"")
        sys.exit(1)
    
    input_str = sys.argv[1]
    
    try:
        uint32_values = convert_byte_array_to_uint32(input_str)
        output_c_array = generate_output_c_array(uint32_values)
        
        with open("output.txt", "w") as f:
            f.write(output_c_array)
        
        print("Conversion successful. Output written to output.txt")
        print(f"Original byte count: {len(uint32_values)*4}")
        print(f"Converted uint count: {len(uint32_values)}")
        
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
