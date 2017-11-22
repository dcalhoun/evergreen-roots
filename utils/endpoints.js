import fetch from 'isomorphic-unfetch';

export const fetchListings = async () => {
  return fetch(`${__ENV__.host}/api/listings`);
};
