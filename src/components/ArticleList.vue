<template>
  <div class="posts flex-col flex-center">
    <article class="body slide-up-big-in flex-row" v-for="article in articles" :key="article">
      <div class="info pos-rel">
        <div class="meta">
          <span class="item" :title="article.date">
            <span class="icon">
              <i class="ic i-calendar"></i>
            </span>
            <time :datetime="article.date">{{ article.date }}</time>
          </span>
          <span class="item" title="本文字数">
            <span class="icon">
              <i class="ic i-pen"></i>
            </span>
            <span>{{ article.fontNum }}</span>
            <span class="text">字</span>
          </span>
        </div>
        <h3>
          <RouterLink :to="`article${article.path}`" :title="article.title">{{ article.title }}</RouterLink>
        </h3>

        <RouterLink :to="`article${article.path}`" :title="article.title">
          <div class="excerpt">{{ article.description }}</div>
        </RouterLink>

        <div class="meta footer">
          <span>
            <RouterLink :to="`article${article.path}`" :title="article.title">
              <i class="ic i-flag"></i>
              {{ article.title }}
            </RouterLink>
          </span>
        </div>
        <!-- <RouterLink :to="`article${article.path}`" :title="article.title" class="btn">more...</RouterLink> -->
      </div>
    </article>
  </div>
</template>

<script setup>
import { defineProps, toRefs } from "vue";
import { RouterLink } from "vue-router";
const props = defineProps({
  articles: {
    type: Array,
    default: () => [],
  },
});

const { articles } = toRefs(props);
</script>

<style scoped lang='scss'>
.posts {
  .body {
    border-radius: 0.5rem;
    width: calc(100% - 2rem);
    min-width: calc(100% - 2rem);
    transition: all 0.2s ease-in-out 0s;
    box-shadow: 0 0.625rem 1.875rem -0.9375rem var(--box-bg-shadow);

    .info {
      width: 100%;
      perspective: 62.5rem;
      padding: 1rem 1.5rem 3rem !important;

      .meta {
        margin: 0;
        display: flex;
        justify-content: flex-end;
      }

      h3 {
        overflow: hidden;
        white-space: nowrap;
        margin: 0.625rem 0;
        text-overflow: ellipsis;
        color: var(--primary-color);
      }

      .excerpt {
        overflow: hidden;
        font-size: 0.875em;
        max-height: 5rem;
        display: -webkit-box;
        -webkit-box-orient: vertical;
        -webkit-line-clamp: 3;
        text-overflow: ellipsis;
      }
    }

    @media (max-width: 767px) {
      .info {
        width: 100%;
        height: 14rem;
        padding: 0 1rem 3rem;

        .meta .item:not(:first-child) {
          display: none;
        }
      }
    }
  }

  .body:hover {
    box-shadow: 0 0 2rem var(--box-bg-shadow);
  }

  // .body:nth-child(even) {
  //   flex-direction: row-reverse;

  //   .info {
  //     padding: 1rem 0 3rem 1.5rem;

  //     .meta {
  //       justify-content: flex-start;
  //     }

  //     .footer {
  //       right: 0.5rem;
  //     }
  //   }

  //   .btn {
  //     left: 0;
  //     right: auto;
  //     border-radius: 0 0.25rem;
  //     background-image: linear-gradient(to right,
  //         var(--color-orange) 0,
  //         var(--color-pink) 100%);
  //   }
  // }

  @media (max-width: 767px) {
    // .body:nth-child(even) {
    //   flex-direction: column;

    //   .info {
    //     padding: 0 1rem 3rem;
    //   }
    // }

    .body {
      width: 100%;
      flex-direction: column;
      height: -webkit-fit-content;
      height: -moz-fit-content;
      height: fit-content;
      max-height: -webkit-fit-content;
      max-height: -moz-fit-content;
      max-height: fit-content;
    }
  }

  .body+.body {
    margin-top: 0.625rem;
  }
}
</style>
