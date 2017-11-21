import ErrorMessage from '../components/ErrorMessage';
import EtsyListings from '../containers/EtsyListings';
import Head from 'next/head';
import Listings from '../components/Listings';
import Loading from '../components/Loading';
import React from 'react';

const Index = props => (
  <div>
    <Head>
      <title>Evergreen Roots</title>
      <meta name="viewport" content="initial-scale=1.0, width=device-width" />
    </Head>
    <EtsyListings>
      {({ error, isFetching, items }) =>
        error ? (
          <ErrorMessage title={error} />
        ) : isFetching ? (
          <Loading />
        ) : (
          <Listings items={items} />
        )
      }
    </EtsyListings>
  </div>
);

Index.displayName = 'Index';

export default Index;
