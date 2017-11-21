import Listing from '../components/Listing';
import PropTypes from 'prop-types';
import React from 'react';

const Listings = props =>
  props.items.map(item => (
    <Listing key={item.listing_id} price={item.price} title={item.title} />
  ));

Listings.displayname = 'Listings';

Listings.propTypes = {
  items: PropTypes.array.isRequired,
};

export default Listings;
