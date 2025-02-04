import React from 'react';

const Redirect: React.FC<React.PropsWithChildren<{ path: string }>> = ({ path }) => {
  React.useEffect(() => {
    setTimeout(() => {
      window.location.href = path;
    }, 0);
  });

  return null;
};

export default Redirect;
