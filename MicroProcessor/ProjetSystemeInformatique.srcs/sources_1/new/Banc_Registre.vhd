----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10.04.2026 11:29:27
-- Design Name: 
-- Module Name: Banc_Registre - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Banc_Registre is
    Port (
        -- Port A
        ADDR_A : in  STD_LOGIC_VECTOR(3 downto 0);
        QA     : out STD_LOGIC_VECTOR(7 downto 0);

        -- Port B
        ADDR_B : in  STD_LOGIC_VECTOR(3 downto 0);
        QB     : out STD_LOGIC_VECTOR(7 downto 0);

        -- Write
        ADDR_W : in  STD_LOGIC_VECTOR(3 downto 0);
        DATA   : in  STD_LOGIC_VECTOR(7 downto 0);
        W      : in  STD_LOGIC;

        -- SIGNALS
        RST    : in  STD_LOGIC;
        CLK    : in  STD_LOGIC
    );
end Banc_Registre;

architecture Behavioral of Banc_Registre is
    -- Registers
    type t_reg_array is array(15 downto 0) of std_logic_vector(7 downto 0); -- https://fpgatutorial.com/vhdl-records-arrays-and-custom-types/
    signal registers : t_reg_array := (others => "00000000");

begin

    -- Port A rw
    QA <= DATA when (W = '1' and ADDR_W = ADDR_A)
        else registers(to_integer(unsigned(ADDR_A)));

    -- Port B rw
    QB <= DATA when (W = '1' and ADDR_W = ADDR_B)
        else registers(to_integer(unsigned(ADDR_B)));

    -- Clocked process for writes and reset
    process(CLK)
    begin
        if rising_edge(CLK) then
            if RST = '1' then
                registers <= (others => "00000000");  -- Clear all
            elsif W = '1' then    -- If write enabled
                registers(to_integer(unsigned(ADDR_W))) <= DATA;  -- Write data
            end if;
        end if;
    end process;

end Behavioral;
