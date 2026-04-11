----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 19.03.2026 22:42:28
-- Design Name: 
-- Module Name: Compteur_8bits - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

entity Compteur_8bits is
    Port ( CK : in STD_LOGIC;
           RST : in STD_LOGIC; -- actif bas
           LOAD : in STD_LOGIC; -- actif haut
           SENS : in STD_LOGIC;
           EN : in STD_LOGIC; -- actif bas
           Din : in STD_LOGIC_VECTOR (7 downto 0);
           Dout : out STD_LOGIC_VECTOR (7 downto 0));
end Compteur_8bits;

architecture Behavioral of Compteur_8bits is
    signal compteur : unsigned(7 downto 0) := (others => '0');
begin

    process(CK, RST, LOAD, SENS, EN, Din) is
    begin
        if rising_edge(CK) then
            if RST = '0' then
                compteur <= (others => '0');
            elsif LOAD = '1' then
                compteur <= unsigned(Din);
            elsif EN = '0' then
                if SENS = '1' then
                    compteur <= compteur + 1;
                else 
                    compteur <= compteur - 1;
                end if;
            end if;
        end if;
    end process;

    Dout <= STD_LOGIC_VECTOR(compteur);

end Behavioral;