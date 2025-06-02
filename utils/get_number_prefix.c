#include "../ft_printf.h"

char  *get_number_prefix(t_data *data, int is_negative, unsigned long long value)
{
  if (is_in("diu", data->format.specifier))
  {
    if (is_negative)
      return ("-");
    else if (data->foramt.plus)
      return ("+");
    else if (data->format.space)
      return (" ");
  }
  if (data->format.hash && value != 0)
  {
    if (data->format.specifier == 'x')
      return ("0x");
    else if (data->format.specifier == 'X')
      return ("0X);
  }
  if (data->format.specifier == 'p')
        return ("0x");
  return ("");
}
