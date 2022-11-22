<template>
  <div class="side pos-rel" :class="showSide ? 'open' : 'close'" v-show="showSideCopy">
    <div class="links flex-col">
      <div class="item" v-for="link of sidebar.localPath" :key="link">
        <router-link class="link flex-center flex-row" :to="link.url" :class="link.name">
          <div class="flex-row item">
            <i class="ic" :class="link.icon"></i>
          </div>
        </router-link>
        <span>{{ link.title }}</span>
      </div>
      <div class="item" v-for="link of sidebar.socialLinks" :key="link">
        <a :href="link.url" rel="noopener external nofollow noreferrer" target="_blank" class="link" :class="link.name"
          :title="link.url">
          <div class="flex-row item">
            <i class="ic" :class="link.icon"></i>
          </div>
        </a>
        <span>{{ link.title }}</span>
      </div>
    </div>
  </div>
</template>
<script setup>
import { debounce } from '@/utils/util.js'
import { toRefs, defineProps, watch, ref } from "vue";
import config from "../../public/config";
import { RouterLink, useRoute } from "vue-router";
//props
const props = defineProps({
  showSide: {
    type: Boolean,
    default: false,
  },
});
const { showSide } = toRefs(props);

//delay fade
const showSideCopy = ref(false)

const show = debounce(200, () => {
  const newVal = arguments[0]
  if (newVal) {
    showSideCopy.value = newVal
  } else {
    setTimeout(() => {
      showSideCopy.value = newVal
    }, 200)
  }
})

watch(showSide, (newVal, oldVal) => {
  show(newVal)
})
const { sidebar } = config;

</script>

<style lang='scss' scoped>
.side {
  background-color: var(--grey-3);
  transition: all 0.2s ease 0s;
}

[data-theme="dark"] .side {
  background-color: var(--grey-7);
}

@media (max-width: 991px) {
  .side {
    position: fixed;
    top: 0;
    right: 0;
    width: 0;
    height: 100%;
    z-index: 1001;
  }

  .open {
    animation: openFromRight 0.2s ease-in-out forwards;
  }

  .close {
    animation: closeFromLeft 0.2s ease-in-out forwards;
  }
}

@media (min-width: 991px) {
  .side {
    display: none;
  }

}

.links {
  padding: 0.625rem;

  .item {
    display: flex;
    justify-content: space-between;
    align-items: center;
    cursor: pointer;
  }

  .item:hover {
    background-color: var(--color-could8);
  }

  .link {
    width: 1.875rem;
    height: 1.875rem;
    position: relative;
    overflow: hidden;
    border-radius: 38%;

    i {
      font-size: 1.4rem;
      transform: scale(0.8);
      transition: all 0.35s cubic-bezier(0.31, -0.105, 0.43, 1.59) 0s;
    }
  }

  .link::before {
    top: 90%;
    left: -110%;
    content: "";
    width: 120%;
    height: 120%;
    position: absolute;
    transform: rotate(45deg);
    transition: all 0.35s cubic-bezier(0.31, -0.105, 0.43, 1.59) 0s;
  }

  .link:focus::before,
  .link:hover::before {
    top: -10%;
    left: -10%;
  }

  .link:focus i,
  .link:hover i {
    color: var(--grey-0);
    transform: scale(1);
  }

  .could::before {
    background-color: var(--color-morandi-purple);
  }

  .could i {
    color: var(--color-morandi-purple);
  }

  .could1::before {
    background-color: var(--color-could1);
  }

  .could1 i {
    color: var(--color-could1);
  }

  .could2::before {
    background-color: var(--color-could2);
  }

  .could2 i {
    color: var(--color-could2);
  }

  .could3::before {
    background-color: var(--color-could3);
  }

  .could3 i {
    color: var(--color-could3);
  }

  .could4::before {
    background-color: var(--color-could4);
  }

  .could4 i {
    color: var(--color-could4);
  }

  .could5::before {
    background-color: var(--color-could5);
  }

  .could5 i {
    color: var(--color-could5);
  }

  .github::before {
    background-color: #191717;
  }

  .github i {
    color: #191717;
  }

  .twitter::before {
    background-color: #00aff0;
  }

  .twitter i {
    color: #00aff0;
  }

  .zhihu::before {
    background-color: #1e88e5;
  }

  .zhihu i {
    color: #1e88e5;
  }

  .music::before {
    background-color: #e60026;
  }

  .music i {
    color: #e60026;
  }

  .telegram::before {
    background-color: #32afed;
  }

  .telegram i {
    color: #32afed;
  }

  .about::before {
    background-color: #3b5998;
  }

  .about i {
    color: #3b5998;
  }
}
</style>

<style>
@keyframes openFromRight {
  from {
    width: 0;
  }

  to {
    width: 60%;
  }
}

@keyframes closeFromLeft {
  from {
    width: 60%;
  }

  to {
    width: 0;
  }
}
</style>