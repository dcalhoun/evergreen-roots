import fetch from 'isomorphic-unfetch';

export const fetchListings = async () =>
  fetch(`${process.env.HOST}/api/listings`);
